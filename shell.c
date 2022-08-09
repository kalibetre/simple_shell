#include "main.h"
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
