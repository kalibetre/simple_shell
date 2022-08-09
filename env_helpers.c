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

