#include "main.h"
/**
 * _strdup - it duplicates a string
 * @str: The pointer to string to duplicate
 *
 * Return: The pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length;
	char *dest_str;

	if (str == NULL)
		return (NULL);
	for (length = 0; str[length] != '\0'; length++)
		;
	dest_str = malloc(sizeof(char) * (length + 1));
	if (dest_str == NULL)
		return (NULL);

	for (length = 0; str[length] != '\0'; length++)
	{
		dest_str[length] = str[length];
	}
	dest_str[length] = '\0';

	return (dest_str);
}
/**
 * _strcmp - it compares two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * Return: 1 if true, 0 if false
 */
int _strcmp(char *s1, char *s2)
{
	int c;

	c = 0;
	while (s1[c] != '\0' && s2[c] != '\0')
	{
		if (s1[c] != s2[c])
		{
			return (s1[c] - s2[c]);
		}
		c++;
	}
	return (0);
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
	int c;
	int c2;

	c = 0;
	while (dest[c] != '\0')
	{
		c++;
	}
	c2 = 0;
	while (src[c2] != '\0')
	{
		dest[c] = src[c];
		c++;
		c2++;
	}
	dest[c] = '\0';
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
	int longi;

	while (*s != '\0')
	{
		longi++;
		s++;
	return (longi);
}
