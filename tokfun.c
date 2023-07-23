#include "main.h"
/**
 * tokenizer - transforms string into separate tokens
 * @buff: pointer to string to tokenize
 *
 * Return: pointer to pointers to each token or NULL
 */
char **tokenizer(char *buff)
{
	int i = 0, counter = 0;
	char *tok, *delimiter = " \n";
	char **result;

	counter = _strpliter(buff);
	if (!counter)
		return (NULL);
	result = malloc((counter + 1) * sizeof(char *));
	if (result == NULL)
		exit(1);
	tok = strtok(buff, delimiter);
	while (tok != NULL)
	{
		result[i] = _strdup(tok);
		tok = strtok(NULL, delimiter);
		i++;
	}
	result[i] = NULL;
	return (result);
}

/**
 * splitter - counts the number of paths in PATH
 * @s: poinbter to PATH string
 *
 * Return: number of directories to check in PATH
 */
int splitter(char *s)
{
	int i;
	int flag = 1, counter = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] != ':' && flag == 1)
		{
			counter = counter + 1;
			flag = 0;
		}
		if (s[i + 1] == ':')
			flag = 1;
	}
	return (counter);
}

/**
 * comparepath - finds value of PATH in environ
 * @str1: pointer to "PATH"
 * @str2: pointer to environ string
 *
 * Return: 0 on success or +1 if no PATH variable in environ
 */

int comparepath(const char *str1, const char *str2)
{
	int i;

	for (i = 0; str2[i] != '='; i++)
	{
		if (str1[i] != str2[i])
			return (-1);
	}
	return (0);
}

/**
 * completeconcat - concatenates 3 strings to create a full path to command exe
 * @str: string to store the result of the concatenation
 * @av: pointer to command string entered by user
 * @token: pointer to first part of a directory in PATH
 *
 * Return: pointer to the complete path to the command
 */

char *completeconcat(char *str, char **av, char *token)
{
	int len, len1, len2;

	_memset(str, 0, 256);
	len1 = _strlen(token);
	len2 = _strlen(av[0]);
	len = len1 + len2 + 2;
	_strcat(str, token);
	_strcat(str, "/");
	_strcat(str, av[0]);

	str[len - 1] = '\0';

	return (str);
}
