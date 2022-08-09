#include "main.h"

/**
 * exit_shell - exit's the shell
 * @sh_name: the name of the current shell
 * @c_args: command to be executed by the builtin
 * @cmd_num: the line number of the command
 * @env_ls: the environment variables
 *
 * Return: status of the function execution
 */
int exit_shell(char *sh_name, char **c_args, int cmd_num, EnvList **env_ls)
{
	int exit_status = EXIT_SUCCESS;

	(void)sh_name;
	(void)cmd_num;
	(void)env_ls;

	if (c_args[1] != NULL)
		exit_status = _atoi(c_args[1]);

	free_str_ary(c_args);
	free_env_list(*env_ls);
	exit(exit_status);
}

/**
 * print_env - prints the current environment variables
 * @sh_name: the name of the current shell
 * @c_args: command to be executed by the builtin
 * @cmd_num: the line number of the command
 * @env_ls: the environment variables
 *
 * Return: status of the function execution
 */
int print_env(char *sh_name, char **c_args, int cmd_num, EnvList **env_ls)
{
	(void)sh_name;
	(void)cmd_num;
	(void)c_args;

	print_env_list(*env_ls);

	return (0);
}

