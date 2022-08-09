#include "main.h"

/**
 * main - a simple shell program that works in both interactive
 * and non interactive mode
 * @argc: the number of arguments passed
 * @argv: the arguments
 * @env: shell environment variables
 *
 * Return: 0 on success
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;

	run_shell(argv, env);
	(void)argv;
	return (0);
}
