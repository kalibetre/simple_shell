#include "main.h"

/**
 * str_ary_dup - duplicates an array of strings
 * @ary: the array to be duplicated
 * @start_index: the start index
 * @count: the number items to copy
 *
 * Return: returns the duplicated array or NULL
 */
char **str_ary_dup(char **ary, size_t start_index, size_t count)
{
	char **dup;
	size_t i;

	dup = malloc(sizeof(char *) * count);
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < count; i++)
		dup[i] = _strdup(ary[i + start_index]);

	return (dup);
}

/**
 * free_str_ary - free an array of strings
 * @ary: the array of strings to be freed
 */
void free_str_ary(char **ary)
{
	int i;

	for (i = 0; ary[i] != NULL; i++)
		free(ary[i]);

	free(ary);
}

/**
 * str_to_ary - splits a string to an array of strings
 * @str: the string
 * @delim: the delimiter string
 * @size: the size of the returned array
 *
 * Return: an array of substrings from the string
 */
char **str_to_ary(char *str, const char *delim, int *size)
{
	int i = 0;
	char **ary;
	char *token;

	*size = count_tokens(str, delim[0]);
	if (*size == 0)
		return (NULL);
	*size += 1;
	ary = malloc(sizeof(char *) * (*size));
	if (ary == NULL)
		return (NULL);

	token = _strtok(str, delim);
	while (token != NULL)
	{
		ary[i] = _strdup(token);
		free(token);
		token = _strtok(NULL, delim);
		i++;
	}

	ary[*size - 1] = NULL;
	return (ary);
}

/**
 * count_tokens - gets the number of tokens in a string
 * separated by spaces
 * @str: the string
 * @delim: the delim char
 *
 * Return: number of tokens
 */
int count_tokens(char *str, char delim)
{
	int count = 0;

	if (str == NULL)
		return (count);

	while (*str != '\0')
	{
		if (*str != delim)
		{
			count++;
			while (*str != delim && *str != '\0')
				str++;
		}
		else
			str++;
	}
	return (count);
}
