#include "main.h"

/**
 * _realloc - resizes a string created with malloc
 * @str: the original string
 * @size: the new size of the string
 *
 * Return: the new resized string
 */
char *_realloc(char *str, int size)
{
	int old_size = strlen(str), i = 0;
	char *temp;

	if (str == NULL)
	{
		str = (char *)malloc(sizeof(char) * size);
		return (str);
	}

	if (old_size == size)
		return (str);

	temp = (char *)malloc(sizeof(char) * (old_size + size));
	if (temp == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	free(str);
	return (temp);
}
