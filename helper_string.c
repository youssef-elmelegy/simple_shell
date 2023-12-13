#include "shell.h"

/**
 * str_length - give you the length of string..
 * @string: pointer of the string.
 * Return: string length.
 */
int str_length(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length++] != '\0')
	{
	}
	return (--length);
}

/**
 * str_duplicate - duplicates the given string
 * @string: String that will copied
 * Return: pointer to duplicated string.
 */

char *str_duplicate(char *string)
{
	char *dup;
	int length, i;

	if (string == NULL)
		return (NULL);

	length = str_length(string) + 1;

	dup = malloc(sizeof(char) * length);

	if (dup == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < length ; i++)
	{
		dup[i] = string[i];
	}

	return (dup);
}

/**
 * _strchr - Locate the first occurrence of a character in a string.
 * @str: The string to search within.
 * @c: The character to locate.
 *
 * Return: A pointer to the first occurrence of the character c in str,
 *         or NULL if the character is not found.
*/
char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}

/**
 * _strncmp - Compare at most the first n characters of two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 * @n: The maximum number of characters to compare.
 *
 * Return: 0 if str1 is equal to str2.
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && *str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
		n--;
	}
	return (0);
}
