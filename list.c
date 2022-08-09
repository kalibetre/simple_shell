#include "main.h"

/**
 * free_str_list - frees the memory allocated for list
 * @list: pointer to the list
 *
 * Return: Nothing
 */
void free_str_list(list_s *list)
{
	if (list != NULL)
	{
		if (list->next != NULL)
			free_str_list(list->next);

		free(list->str);
		free(list);
	}
}
