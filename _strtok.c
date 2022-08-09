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

/**
 * _strtok - returns the next token in the string delimited
 * by the delimiters specified
 * @str: the string
 * @delims: the delimiters
 *
 * Return: the next token or NULL
 */
char *_strtok(char *str, const char *delims)
{
	static char *ch_ptr;
	char *token;
	int count = 0, i;

	if (str != NULL)
		ch_ptr = str;

	if (ch_ptr == NULL)
		return (NULL);

	for (i = 0; delims[i] != '\0'; i++)
		skip_delim(&ch_ptr, delims[i]);

	if (*ch_ptr == '\0')
		return (NULL);

	count = count_until_delim(ch_ptr, delims);
	if (count == -1)
		count = strlen(ch_ptr);

	token = (char *)malloc(sizeof(char) * (count + 1));
	for (i = 0; i < count; i++)
	{
		token[i] = *ch_ptr;
		ch_ptr++;
	}
	token[count] = '\0';

	return (token);
}
