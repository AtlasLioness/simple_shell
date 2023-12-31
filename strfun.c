#include "main.h"

/**
 * _strdup - it duplicates a string
 * @str: The pointer to string to duplicate
 *
 * Return: The pointer to the duplicated string
 */
char *_strdup(char *str)
{
	char *dup_str;
	int length;

	if (str == NULL)
		return (NULL);
	for (length = 0; str[length] != '\0'; length++)
		;
	dup_str = malloc(sizeof(char) * (length + 1));
	if (dup_str == NULL)
		return (NULL);

	for (length = 0; str[length] != '\0'; length++)
	{
		dup_str[length] = str[length];
	}
	dup_str[length] = '\0';
	return (dup_str);
}
/**
 * _strcmp - it compares two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * Return: 1 if true, 0 if false
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}
/**
 * _strcat - it concatenates two strings
 * @dest: the destination string
 * @src: the source string
 *
 * Return: pointer to resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}
/**
 * _strlen - returns the length of a string
 * @s: string parameter input
 *
 * Return: integer type
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}
	return (longi);
}

/**
 * _strplitter - gets number of words in string
 * @s: pointer to string
 *
 * Return: number of words
 */
int _strplitter(char *s)
{
	int i, flag = 1, counter = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] != ' ' && flag == 1)
		{
			counter += 1;
			flag = 0;
		}
		if (s[i + 1] == ' ')
			flag = 1;
	}
	return (counter);
}
