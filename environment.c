#include "main.h"

/**
 * build_env_list - converts an array of env vars to list
 * @sh_name: the name of the current shell
 * @env: array of environment variables
 *
 * Return: EnvList pointer or NULL
 */
EnvList *build_env_list(char *sh_name, char **env)
{
	EnvList *list = NULL;
	int i = 0;
	char **temp_env_var = NULL, **c_args = NULL;
	int size;

	while (env[i] != NULL)
	{
		c_args = malloc(sizeof(char *) * 4);
		if (c_args == NULL)
			print_error(sh_name, 1, "env", "Unable to allocated memory");
		temp_env_var = str_to_ary(env[i], "=", &size);
		c_args[0] = _strdup("setenv");
		c_args[1] = _strdup(temp_env_var[0]);
		c_args[2] = _strdup(temp_env_var[1]);
		c_args[3] = NULL;

		_set_env(sh_name, c_args, 1, &list);

		free_str_ary(temp_env_var);
		free_str_ary(c_args);

		i++;
	}

	return (list);
}

/**
 * _set_env - sets an environment variable
 * @sh_name: the name of the current shell
 * @c_args: command to be executed by the builtin
 * @cmd_num: the line number of the command
 * @env_ls: the environment variables
 *
 * Return: Nothing
 */
void _set_env(char *sh_name, char **c_args, int cmd_num, EnvList **env_ls)
{
	EnvList *node, *prev;

	node = _getenv(c_args[1], *env_ls, &prev);
	if (node == NULL)
	{
		node = malloc(sizeof(EnvList));
		if (node == NULL)
		{
			print_error(sh_name, cmd_num, c_args[0], "Failed to allocate memory");
			return;
		}
		if (set_env_key_value(c_args[1], c_args[2], &node) == -1)
		{
			free(node);
			print_error(sh_name, cmd_num, c_args[0], "Failed to set env variable");
			return;
		}
		node->next = NULL;
		if (env_ls == NULL)
			*env_ls = node;

		node->next = *env_ls;
		*env_ls = node;
	}
	else
	{
		free(node->value);
		if (set_env_value(c_args[2], &node) == -1)
		{
			free(node);
			print_error(sh_name, cmd_num, c_args[0], "Failed to set env variable");
			return;
		}
	}
}

/**
 * set_env_key_value - copies key and value to an environment variable
 * @key: key of the environment variable
 * @value: value of the environment variable
 * @node: pointer to an env node
 *
 * Return: Nothing
 */
int set_env_key_value(char *key, char *value, EnvList **node)
{
	(*node)->key = _strdup(key);
	if ((*node)->key == NULL)
		return (-1);
	return (set_env_value(value, node));
}

/**
 * set_env_value - sets value to an environment variable
 * @value: value of the environment variable
 * @node: pointer to an env node
 *
 * Return: Nothing
 */
int set_env_value(char *value, EnvList **node)
{
	(*node)->value = _strdup(value);
	if ((*node)->value == NULL)
	{
		free((*node)->key);
		return (-1);
	}
	return (0);
}

