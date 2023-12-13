#include "shell.h"

/**
 * _strcpy - Copy a string from source to destination.
 * @destination: Pointer to the destination buffer.
 * @source: Pointer to the source string.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *destination, const char *source)
{
	char *oDestination = destination;

	while ((*destination++ = *source++) != '\0')
	{
	}

	return (oDestination);
}

/**
 * _strcat - Concatenate two strings.
 * @destination: Pointer to the destination buffer.
 * @source: Pointer to the source string.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcat(char *destination, char *source)
{
	char *original_destination = destination;
	int destination_length = 0;
	int source_length = 0;

	destination_length = str_length(destination);
	source_length = str_length(source);

	if (destination_length + source_length + 1 > str_length(original_destination))
	{
		destination = realloc(destination, destination_length + source_length + 1);
	if (!destination)
	{
		return (NULL);
	}
	}

	_strcpy(destination + destination_length, source);
	return (original_destination);
}

/**
 * _strcmp - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 *
 * Return: 0 if strings are equal.
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}
