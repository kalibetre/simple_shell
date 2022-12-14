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

/**
 * _strdup - duplicates a given string
 * @str: the string to be duplicated
 *
 * Return: a malloc'd string
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *dup;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	len++;
	dup = malloc(sizeof(char) * len);
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len - 1; i++)
		dup[i] = str[i];

	dup[i] = '\0';
	return (dup);
}

/**
 * _strcat - concatenates src string to dest string
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 *
 * Return: pointer to the dest string
 */
char *_strcat(char *dest, char *src)
{
	int dest_i = 0, src_i = 0;

	while (*(dest + dest_i) != '\0')
		dest_i++;

	while (*(src + src_i) != '\0')
	{
		*(dest + dest_i) = *(src + src_i);
		dest_i++;
		src_i++;
	}

	*(dest + dest_i) = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: positive if s1 greater, negative if lesser or 0
 */
int _strcmp(char *s1, char *s2)
{
	int index = 0;

	while (*(s1 + index) != '\0' && *(s2 + index) != '\0')
	{
		if (*(s1 + index) != *(s2 + index))
			return (*(s1 + index) - *(s2 + index));
		index++;
	}

	if (*(s1 + index) != '\0' || *(s2 + index) != '\0')
		return (*(s1 + index) != '\0' ? *(s1 + index) : *(s2 + index) * -1);

	return (0);
}
