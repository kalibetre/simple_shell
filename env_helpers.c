#include "main.h"

/**
 * print_env_list - frees the allocated memory for an env_list
 * @list: the list to be printed
 *
 * Return: Nothing
 */
void print_env_list(EnvList *list)
{
	while (list != NULL)
	{
		_puts_mul(3, list->key, "=", list->value);
		list = list->next;
	}
}

/**
 * free_env_list - frees the allocated memory for an env_list
 * @list: the list to be printed
 *
 * Return: Nothing
 */
void free_env_list(EnvList *list)
{
	EnvList *temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;

		free(temp->key);
		free(temp->value);
		free(temp);
	}
}

