#include "main.h"

/**
 * run_shell - runs a simple shell until the user exits
 * @argv: the program's argument variables
 * @env: the environment variables of the shell
 *
 * Return: Nothing
 */
void run_shell(char **argv, char **env)
{
	int status = 0, cmd_num = 0, i, arr_size = 0;
	char *line = NULL;
	char **c_args = NULL;
	ssize_t line_len = 0;
	EnvList *env_ls;

	env_ls = build_env_list(argv[0], env);
	do {
		cmd_num++;
		if (isatty(STDIN_FILENO))
			_print("#cisfun$ ");
		else
			run_shell_non_interactive(argv, &env_ls);
		signal(SIGINT, ctrl_c_handler);
		line = NULL;
		line_len = read_line(&line);
		ctrl_d_handler(line_len, line, env_ls);
		i = 0;
		while (line[i] != '\n')
			i++;
		line[i] = '\0';
		if (line[0] == '\0')
		{
			free(line);
			continue;
		}
		c_args = str_to_ary(line, " ", &arr_size);
		free(line);
		if (c_args == NULL)
			continue;

		if (_strcmp(c_args[0], "exit") == 0)
			exit_shell(argv[0], cmd_num, status, c_args, &env_ls);
		status = execute_input(argv, c_args, cmd_num, &env_ls);
		free_str_ary(c_args);
	} while (status == 0);

	free_env_list(env_ls);
	exit(status);
}

/**
 * free_env_and_exit - free env and exit with code
 * @exit_code: exit code
 * @env_ls: env list
 */
void free_env_and_exit(int exit_code, EnvList *env_ls)
{
	free_env_list(env_ls);
	exit(exit_code);
}

/**
 * run_shell_non_interactive - runs a simple shell until the user exits
 * @argv: the program's argument variables
 * @env_ls: the environment variables of the shell
 *
 * Return: Nothing
 */
void run_shell_non_interactive(char **argv, EnvList **env_ls)
{
	int status = 0, cmd_num = 0, count, i = 0, arr_size = 0;
	char *line = NULL, **commands = NULL, **c_a = NULL;

	if (read_file(&line) == 0)
	{
		free(line);
		free_env_and_exit(EXIT_SUCCESS, *env_ls);
	}
	commands = str_to_ary(line, "\n", &count);
	free(line);
	if (commands == NULL)
	{
		free_str_ary(commands);
		free_env_and_exit(EXIT_SUCCESS, *env_ls);
	}
	while (commands[i] != NULL)
	{
		c_a = str_to_ary(commands[i], " ", &arr_size);
		free(commands[i]);
		cmd_num++;
		if (c_a == NULL)
		{
			i++;
			continue;
		}
		if (_strcmp(c_a[0], "exit") == 0)
		{
			if (c_a[1] == NULL || (c_a[1] != NULL && _atoi(c_a[1]) != -1))
				free(commands);
			exit_shell(argv[0], cmd_num, status, c_a, env_ls);
			i++;
			continue;
		}
		status = execute_input(argv, c_a, cmd_num, env_ls);
		free_str_ary(c_a);
		i++;
	}
	free(commands);
	free_env_and_exit(status, *env_ls);
}

/**
 * execute_input - executes a input string
 * @argv: the arguments passed form main
 * @c_args: the commands
 * @cmd_num: the line number of the command
 * @env_ls: the environment variables
 *
 * Return: status of the execution result
 */
int execute_input(char **argv, char **c_args, int cmd_num, EnvList **env_ls)
{
	char *executable = NULL;
	int status = 0;
	int (*builtin_func)(char *, char **, int, EnvList **);

	if (c_args == NULL)
		return (0);

	builtin_func = get_builtin(c_args[0]);
	if (builtin_func != NULL)
		status = builtin_func(argv[0], c_args, cmd_num, env_ls);
	else
	{
		if (access(c_args[0], F_OK) != 0)
		{
			executable = find_in_path(c_args[0], *env_ls);
			if (executable == NULL)
			{
				print_error(argv[0], cmd_num, c_args[0], "not found");
				return (127);
			}
			else
			{
				free(c_args[0]);
				c_args[0] = _strdup(executable);
				free(executable);
				status = run_child_process(argv[0], cmd_num, c_args, env_ls);
			}
		}
		else
			status = run_child_process(argv[0], cmd_num, c_args, env_ls);
	}
	return (status);
}

/**
 * run_child_process - starts a child process to execute the
 * given argument with the specified environment variables
 * @sh_n: the name of the current shell
 * @cmd_num: the command count
 * @c_args: command to be executed by the process
 * @env_ls: the environment variables
 *
 * Return: 0 on success
 */
int run_child_process(char *sh_n, int cmd_num, char **c_args, EnvList **env_ls)
{
	int status = 0;
	pid_t child_pid;
	char **env = NULL;

	child_pid = fork();
	if (child_pid == -1)
		return (1);

	if (child_pid == 0)
	{
		env = env_list_to_ary(*env_ls);
		if (execve(c_args[0], c_args, env) == -1)
		{
			print_error(sh_n, cmd_num, c_args[0], "not found");
			free_env_list(*env_ls);
			free_str_ary(c_args);
			free_str_ary(env);
			_exit(127);
		}
		free_str_ary(env);
	}
	else
		wait(&status);

	if (WIFEXITED(status))
		return (0);
	return (1);
}
