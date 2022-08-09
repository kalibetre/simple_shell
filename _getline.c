#include "main.h"

/**
 * _getline - reads a line from the standard input
 * @line: pointer to the line to be read
 *
 * Return: the size of the line read from stdin
 */
ssize_t _getline(char **line)
{
	char buffer[1024];
	ssize_t buffer_rd = 0, line_len = 0;

	do {
		buffer_rd = read(STDIN_FILENO, buffer, 1023);
		if (buffer_rd == 0)
			break;
		if (buffer_rd == -1)
			return (-1);
		buffer[buffer_rd] = '\0';
		line_len += buffer_rd;
		if (*line == NULL)
		{
			*line = malloc(sizeof(char) * (buffer_rd + 1));
			(*line)[0] = '\0';
		}
		else if (line_len > (ssize_t)sizeof(buffer))
			*line = _realloc(*line, line_len);

		*line = _strcat(*line, buffer);
		if ((*line)[line_len - 1] == '\n')
			break;
	} while (1);

	if (line_len >= 1)
		(*line)[line_len - 1] = '\0';
	return (line_len);
}
