#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
/**
 * _putchar_er - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar_er(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
/**
 * _print - prints a string followed
 * @str: c-string
 *
 * Return: Nothing
 */
void _print(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}
/**
 * _puts - prints a string followed by a new line
 * @str: c-string
 *
 * Return: void
 */
void _puts(char *str)
{
	_print(str);
	_putchar('\n');
}
