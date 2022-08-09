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

/**
 * add_to_list - adds an element to a list
 * @head: pointer to the head of a list
 * @str: data to be added
 *
 * Return: a pointer to the list or NULL
 */
list_s *add_to_str_list(list_s **head, const char *str)
{
	list_s *node;

	if (str == NULL)
		return (NULL);

	node = malloc(sizeof(list_s));
	if (node == NULL)
		return (NULL);

	node->str = _strdup((char *)str);
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}

	if (head == NULL)
	{
		node->next = NULL;
		return (node);
	}

	node->next = *head;
	*head = node;
	return (node);
}