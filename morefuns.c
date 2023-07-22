#include "main.h"
/**
 * _getenv - it gets the PATH
 * @name: the environ variable name
 *
 * Return: the pointer to the PATH, or NULL if fails
 */
char *_getenv(const char *name)
{
	int i;
	int result;

	for (i = 0; environ[i]; i++)
	{
		result = _PATHstrcmp(name, environ[i]);
		if (result == 0)
		{
			return (environ[i]);
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
	int c;

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
 * _memset - it fills a block of memory with a specific value
 * @s: pointer to the memory to be filled
 * @b: character to fill the memory with
 * @n: Number of bytes to be filled.
 *
 * Return: the pointer to the filled memory
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
		s[a] = b;
	return (s);
}
