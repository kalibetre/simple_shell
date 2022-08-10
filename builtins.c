#include "main.h"

/**
 * exit_shell - exit's the shell
 * @sh_nm: the name of the current shell
 * @num: the line number of the command
 * @st: the line number of the command
 * @c_ag: command to be executed the builtin
 * @env_ls: the environment variables
 *
 * Return: status of the function execution
 */
void exit_shell(char *sh_nm, int num, int st, char **c_ag, EnvList **env_ls)
{
	char *msg;
	char *i_msg = "Illegal number: ";

	if (c_ag[1] != NULL)
		st = _atoi(c_ag[1]);

	if (st == -1)
	{
		msg = malloc(sizeof(char) * (_strlen(i_msg) + _strlen(c_ag[1])) + 1);
		msg[0] = '\0';
		msg = _strcat(msg, i_msg);
		msg = _strcat(msg, c_ag[1]);
		print_error(sh_nm, num, c_ag[0], msg);
		free(msg);
		free_str_ary(c_ag);
	}
	else
	{
		free_env_list(*env_ls);
		free_str_ary(c_ag);
		exit(st);
	}
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

/**
 * set_env - sets an environment variable
 * @sh_name: the name of the current shell
 * @c_args: command to be executed by the builtin
 * @cmd_num: the line number of the command
 * @env_ls: the environment variables
 *
 * Return: status of the function execution
 */
int set_env(char *sh_name, char **c_args, int cmd_num, EnvList **env_ls)
{
	if (c_args[1] == NULL)
		print_error(sh_name, cmd_num, c_args[0], "Key and Value Required");
	else if (c_args[2] == NULL)
		print_error(sh_name, cmd_num, c_args[0], "Value required");
	else
		_set_env(sh_name, c_args, cmd_num, env_ls);
	return (0);
}

/**
 * unset_env - sets an environment variable
 * @sh_name: the name of the current shell
 * @c_args: command to be executed by the builtin
 * @cmd_num: the line number of the command
 * @env_ls: the environment variables
 *
 * Return: status of the function execution
 */
int unset_env(char *sh_name, char **c_args, int cmd_num, EnvList **env_ls)
{
	if (c_args[1] == NULL)
		print_error(sh_name, cmd_num, c_args[0], "Key is required");
	else
		_unset_env(sh_name, c_args, cmd_num, env_ls);
	return (0);
}

/**
 * _chdir - changes the current working directory
 * @sh_name: the name of the current shell
 * @c_args: command to be executed by the builtin
 * @cmd_num: the line number of the command
 * @env_ls: the environment variables
 *
 * Return: status of the function execution
 */
int _chdir(char *sh_name, char **c_args, int cmd_num, EnvList **env_ls)
{
	char *old_pwd, *pwd, *dir = NULL, **env_w_args;
	EnvList *env_dir, *prev;

	if (c_args[1] == NULL)
	{
		env_dir = _getenv("HOME", *env_ls, &prev);
		dir = _strdup(env_dir->value);
	}
	else if (_strcmp(c_args[1], "-") == 0)
	{
		env_dir = _getenv("OLDPWD", *env_ls, &prev);
		if (env_dir == NULL)
		{
			print_error(sh_name, cmd_num, c_args[0], "OLDPWD not set");
			return (0);
		}
		dir = _strdup(env_dir->value);
	}
	else
		dir = _strdup(c_args[1]);

	old_pwd = getcwd(NULL, 0);
	if (chdir(dir) == -1)
	{
		free(old_pwd);
		print_error(sh_name, cmd_num, c_args[0], "Unable to change directory.");
		return (0);
	}
	pwd = getcwd(NULL, 0);

	env_w_args = get_c_args(c_args[0], "OLDPWD", old_pwd);
	_set_env(sh_name, env_w_args, cmd_num, env_ls);
	free_str_ary(env_w_args);
	env_w_args = get_c_args(c_args[0], "PWD", pwd);
	_set_env(sh_name, env_w_args, cmd_num, env_ls);
	free_str_ary(env_w_args);
	free(old_pwd);
	free(pwd);
	free(dir);
	return (0);
}
