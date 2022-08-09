#include "main.h"
/**
 * print_error - prints to the stderr
 * @shell: the current shell
 * @num: the command count
 * @command: command that caused the error
 * @message: error message
 */
void print_error(char *shell, int num, char *command, char *message)
{
	write(STDERR_FILENO, shell, _strlen(shell));
	write(STDERR_FILENO, ": ", 2);
	print_err_number(num);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, "\n", 1);
}
/**
 * print_err_number - prints integer number
 * @n: number to be printed
 *
 * Return: 0
 */
