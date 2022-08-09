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
