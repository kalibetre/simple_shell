#include "main.h"

/**
 * count_until_delim - returns the number of chars until
 * the next delimiter
 * @str: the string
 * @delim: the delimiters
 *
 * Return: the number of chars until delim
 */
int count_until_delim(char *str, const char *delim)
{
	int count = 0, i;

	while (*str != '\0')
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (delim[i] == *str)
				return (count);
		}
		count++;
		str++;
	}
	return (-1);
}

/**
 * skip_delim - skips repeated delimiters
 * @str: the string
 * @delim: the delimiter to skip
 */
void skip_delim(char **str, char delim)
{
	while (*(*str) == delim)
		(*str)++;
}
