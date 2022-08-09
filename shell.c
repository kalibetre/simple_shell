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

		line_len = _getline(&line);
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
