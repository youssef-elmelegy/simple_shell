#include "shell.h"

/**
 * exec - function that execute the command
 * @argv: array of the command
 *
 * Return: void
*/

void *exec(char **argv)
{
	char *line = NULL, *rel_line = NULL;

	if (!argv)
	{
		return (NULL);
	}

	line = argv[0];
	rel_line = path_finder(line);

	if (!rel_line)
	{

		free(line);
		return (NULL);
	}
	if (execve(rel_line, argv, NULL) == -1)
	{
		perror("execve failed");
	}
	free(rel_line);
	return (NULL);
}
