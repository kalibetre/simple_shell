#include "main.h"

/**
 * make_path - joins directory with file to make a path
 * @parent_dir: the parent directory
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
