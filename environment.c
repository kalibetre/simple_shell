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

