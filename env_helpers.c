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

/**
 * env_list_to_ary - convert environment list to array
 * @env_ls: the list containing the environment variables
 *
 * Return: a NULL terminated array of strings
 */
char **env_list_to_ary(EnvList *env_ls)
{
	int size = 0, i, str_len;
	EnvList *head = env_ls;
	char **env;

	while (head != NULL)
	{
		size++;
		head = head->next;
	}

	if (size == 0)
		return (NULL);

	env = malloc(sizeof(char *) * (size + 1));
	for (i = 0; env_ls != NULL; i++)
	{
		str_len = _strlen(env_ls->key) + _strlen(env_ls->value) + 2;
		env[i] = malloc(sizeof(char) * str_len);
		env[i][0] = '\0';
		env[i] = _strcat(env[i], env_ls->key);
		env[i] = _strcat(env[i], "=");
		env[i] = _strcat(env[i], env_ls->value);
		env_ls = env_ls->next;
	}
	env[size] = NULL;

	return (env);
}

