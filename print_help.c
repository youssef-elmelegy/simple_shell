#include "shell.h"

/**
 * _print - writes a array of chars in the standar output.
 * @string: pointer to the array of chars.
 *
 * Return: the number of bytes writed or.
*/

int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}


/**
 * print_env - print env.
 * @env: array.
 *
 * Return: void.
*/

void print_env(char *env[])
{
	int i = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		_print(env[i]);
		_print("\n");
	}
}

/**
 * clear_spaces - Removes consecutive spaces outside double quotes and null.
 * @str: string.
 *
 * Return: Modified string with consecutive spaces outside quotes removed.
*/

char *clear_spaces(char *str)
{
	int i, j;
	int q = 0;

	for (i = 0, j = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\"')
		{
			q = !q;
		}
		else if (!isspace(str[i]) || q)
		{
			str[j++] = str[i];
			if (!isspace(str[i]) && !q && (isspace(str[i + 1]) || str[i + 1] == '\0'))
			{
				str[j++] = ' ';
			}
		}
	}

	str[j] = '\0';
	return (str);
}

