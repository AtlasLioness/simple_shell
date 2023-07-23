#include "main.h"
/**
 * _getenviron - it gets the PATH
 * @name: the environ variable name
 *
 * Return: the pointer to the PATH, or NULL if fails
 */
char *_getenviron(const char *name)
{
	int a;
	int env;

	for (a = 0; environ[a]; a++)
	{
		env = comparepath(name, environ[a]);
		if (env == 0)
		{
			return (environ[a]);
		}
	}

	return (NULL);
}
/**
 * _environ - a function that prints the environ
 *
 * Return: 0.
 */
int _environ(void)
{
	int a;

	for (a = 0; environ[a]; a++)
		_puts(environ[a]);

	return (0);
}
/**
 * _puts - prints a string followed by a new line
 * @str: The string to print
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str + 0);
		str++;
	}
	_putchar('\n');
}
/**
 * _putchar - prints a character
 * @c: character to print
 *
 * Return: return value of write syscall
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * builtinschecker - checks if string is a built-in
 * @av: pointer to arguments
 * @buff: pointer to string
 * @exitstatus: execve exit status
 *
 * Return: 1 or 0 if buff is equal to env or not
 */
int builtinschecker(char **av, char *buff, int exitstatus)
{
	int i;

	if (_strcmp(av[0], "env") == 0)
	{
		_environ();
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buff);

		return (1);
	}
	else if (_strcmp(av[0], "exit") == 0)
	{
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buff);
		exit(exitstatus);
	}
	else
		return (0);
}
