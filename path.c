#include "main.h"

/**
 * make_path - joins directory with file to make a path
 * @parent_dir: parent directory
 * @file_name: the executable file name
 *
 * Return: full file path
 */
char *make_path(char *parent_dir, char *file_name)
{
	char *path;

	path = malloc(sizeof(char) * (_strlen(parent_dir) + _strlen(file_name) + 2));
	path[0] = '\0';
	_strcat(path, parent_dir);
	_strcat(path, "/");
	_strcat(path, file_name);

	return (path);
}

/**
 * find_in_path - find a file in the PATH environment variable
 * @file: the executable file name
 * @env_ls: the environment variables
 *
 * Return: pointer to the file name or NULL if not found
 */
char *find_in_path(char *file, EnvList *env_ls)
{
	const char *path_delim = " :\t\r\n";
	char *path;
	list_s *paths, *head;
	struct stat st;
	EnvList *path_env, *prev;

	path_env = _getenv("PATH", env_ls, &prev);
	if (path_env == NULL)
		return (NULL);
	path = _strdup(path_env->value);
	if (path == NULL)
		return (NULL);
	paths = str_to_str_list(path, path_delim);
	free(path);
	head = paths;

	if (paths == NULL)
		return (NULL);
	while (paths != NULL && paths->str != NULL)
	{
		path = make_path(paths->str, file);
		if (stat(path, &st) == 0)
		{
			free_str_list(head);
			return (path);
		}
		free(path);
		paths = paths->next;
	}
	free_str_list(head);
	return (NULL);
}
