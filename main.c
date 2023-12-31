#include "main.h"
#include <stdlib.h>
/**
 * main - shell program
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char *PATH = NULL, *fullpath = NULL;
	char *buff = NULL;
	char **av;
	int exitstatus = 0;

	signal(SIGINT, SIG_IGN);

	PATH = _getenviron("PATH");
	if (PATH == NULL)
		return (-1);
	while (1)
	{
		av = NULL;
		prompt();
		buff = _reader();
		if (*buff != '\0')
		{
			av = tokenizer(buff);
			if (av == NULL)
			{
				free(buff);
				continue;
			}
			fullpath = _path(av, PATH);
			if (builtinschecker(av, buff, exitstatus) == 1)
			{
				free(fullpath);
				free(buff);
				continue;
			}
			exitstatus = _forku(av, buff, fullpath);
		}
		else
			free(buff);
	}
	free(PATH);
	return (0);
}
