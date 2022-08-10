#include "main.h"

/**
 * ctrl_c_handler - ignore Ctrl-C input and prints prompt again
 * @n: takes in int from signal
 */
void ctrl_c_handler(int n)
{
	(void)n;
	_print("\n#cisfun$ ");
}

/**
 * ctrl_d_handler - exits program if Ctrl-D was pressed
 * @i: characters read via get_line
 * @command: user's typed in command
 * @env_ls: environmental variable list
 */
void ctrl_d_handler(int i, char *command, EnvList *env_ls)
{
	if (i == 0)
	{
		free(command);
		free_env_list(env_ls);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
}
