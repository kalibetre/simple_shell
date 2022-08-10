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
	int status = 0, cmd_num = 0;
	char *line = NULL;
	ssize_t line_len = 0;
	size_t line_cap = 0;
	EnvList *env_ls;

	env_ls = build_env_list(argv[0], env);

	do {
		cmd_num++;
		if (isatty(STDIN_FILENO))
		{
			cmd_num = 0;
			_print("#cisfun$ ");
			fflush(stdout);
		}

		/* line_len = _getline(&line); */
		line_len = getline(&line, &line_cap, stdin);
		line[line_len - 1] = '\0';
		if (line_len <= 0)
		{
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			free_env_list(env_ls);
			exit(EXIT_SUCCESS);
		}

		if (line[0] == '\0')
		{
			free(line);
			line = NULL;
			continue;
		}

		status = execute_input(argv, line, cmd_num, &env_ls);
		line = NULL;
	} while (status == 0);

	free_env_list(env_ls);
	exit(status);
}

/**
 * execute_input - executes a input string
 * @argv: the arguments passed form main
 * @input: the input read from stdin
 * @cmd_num: the line number of the command
 * @env_ls: the environment variables
 *
 * Return: status of the execution result
 */
int execute_input(char **argv, char *input, int cmd_num, EnvList **env_ls)
{
	char **c_args = NULL;
	char *executable = NULL;
	int status = 0, arr_size = 0;
	int (*builtin_func)(char *, char **, int, EnvList **);

	c_args = str_to_ary(input, " ", &arr_size);
	free(input);

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
				print_error(argv[0], cmd_num, c_args[0], "not found");
			else
			{
				free(c_args[0]);
				c_args[0] = _strdup(executable);
				free(executable);
				status = run_child_process(c_args, env_ls);
			}
		}
		else
			status = run_child_process(c_args, env_ls);
	}

	free_str_ary(c_args);
	return (status);
}

/**
 * run_child_process - starts a child process to execute the
 * given argument with the specified environment variables
 * @c_args: command to be executed by the process
 * @env_ls: the environment variables
 *
 * Return: 0 on success
 */
int run_child_process(char **c_args, EnvList **env_ls)
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
		execve(c_args[0], c_args, env);
		free_str_ary(env);
	}
	else
		wait(&status);

	if (WIFEXITED(status))
		return (0);
	return (1);
}
