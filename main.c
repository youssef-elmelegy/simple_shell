#include "shell.h"

/**
 * main - A simple shell heart.
 * @ac: integar.
 * @argv: double pointer.
 *
 * Return: 0 if success.
 */

int main(int ac, char **argv)
{

	char *input = NULL, **new_argv = NULL;
	size_t length = 0;
	ssize_t num = 0;
	int i = 0;

	(void)ac;
	while (1)
	{

		num = getline(&input, &length, stdin);
		if (num == EOF)
		{
			free(input);
			return (0);
		}
		new_argv = token(argv, input, num);
		if (new_argv == NULL)
		{
			free(input);
			return (0);
		}
		if (_fork(new_argv) < 0)
		{
			free(input);
			free(new_argv);
			return (0);
		}
		for (i = 0; new_argv[i] != NULL; i++)
		{
			free(new_argv[i]);
		}
		free(new_argv);
		argv = new_argv;
	}
	free(input);
	free(argv);
	return (0);
}

/**
 * path_ finder - geting the path of the command.
 * @command: command.
 *
 * Return: pointer to char.
 */
char *path_finder(char *command)
{
	char *path_c = NULL, *path_token = NULL, *file_path = NULL;
	int command_length = 0;
	struct stat buffer;
	char *path = getenv("PATH");

	if (!path)
	{
		return (NULL);
	}
	path_c = str_duplicate(path);
	command_length = str_length(command);
	path_token = strtok(path_c, ":");

	while (path_token)
	{
		int directory_length = str_length(path_token);

		file_path = malloc(command_length + directory_length + 2);
		if (!file_path)
		{
			free(path_c);
			return (NULL);
		}
		strncpy(file_path, path_token, directory_length);
		file_path[directory_length] = '/';
		strncpy(file_path + directory_length + 1, command, command_length + 1);
		if (stat(file_path, &buffer) == 0)
		{
			free(path_c);
			return (file_path);
		}
		free(file_path);
		path_token = strtok(NULL, ":");
	}
	free(path_c);
	if (stat(command, &buffer) == 0)
	{
		return (str_duplicate(command));
	}
	return (NULL);
}
/**
 * cleanup_and_exit - exit builtin function
 * @argv: argv
 * @c_getin: c_getin
 * Return: NULL
*/

char **cleanup_and_exit(char **argv, char *c_getin)
{
	int i = 0;

	for (i = 0; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
	free(argv);
	free(c_getin);

	return (NULL);
}



/**
 * token - token the string
 * @argv: argv
 * @getin: string
 * @size: size of string
 * Return: argv pointer
 */

char **token(char **argv, char *getin, size_t size)
{
	char *c_getin = NULL, *token = NULL, *delim = " \n";
	int n_tokens = 0, i = 0;

	(void)size;

	c_getin = str_duplicate(getin);
	token = strtok(getin, delim);
	while (token != NULL)
	{
		n_tokens++;
		token = strtok(NULL, delim);
	}
	argv = malloc(sizeof(char *) * (n_tokens + 1));
	if (argv == NULL)
	{
		free(c_getin);
		return (NULL);
	}
	token = strtok(c_getin, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = str_duplicate(token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	if (_strcmp(argv[0], "exit") == 0)
	{
		return (cleanup_and_exit(argv, c_getin));
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		print_env(environ);
	}
	free(c_getin);
	return (argv);
}
