#include "main.h"
/**
 * _memset - fill a block of memory with a constant char
 * @s: pointer to block to fill
 * @b: constant character to fill the block with
 * @n: number or bytes to fill
 *
 * Return: pointer to the filled block
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
