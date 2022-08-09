#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: pointer to the string
 *
 * Return: length of the string
 */
size_t _strlen(char *s)
{
	size_t len = 0;

	if (s == NULL)
		return (0);

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
