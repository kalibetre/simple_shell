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
	if (num > 0)
	{
		print_err_number(num);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, command, _strlen(command));
		write(STDERR_FILENO, ": ", 2);
	}
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * print_err_number - prints integer number
 * @n: number to be printed
 *
 * Return: 0
 */
void print_err_number(int n)
{
	int digit;
	double factor = 1;

	while (n / factor >= 10)
		factor *= 10;

	while (factor >= 1)
	{
		digit = n / factor;
		_putchar_er(n + '0');
		n = n - digit * factor;
		factor /= 10;
	}
}
