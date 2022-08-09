#include "main.h"

/**
 * get_builtin - Get the builtin func object
 * @name: the name of the builtin function
 *
 * Return: the builtin function
 */
int (*get_builtin(char *name))(char *, char * *, int, EnvList * *)
{
	BuiltIn builtIns[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{"cd", _chdir},
		{"\0", NULL}
	};
	int i = 0;

	while (builtIns[i].func != NULL)
	{
		if (strcmp(builtIns[i].name, name) == 0)
			return (builtIns[i].func);
		i++;
	}
	return (NULL);
}
