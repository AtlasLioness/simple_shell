#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/* String Functions */

char *_memset(char *s, char b, unsigned int n);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strplitter(char *s);

/* Shell Core */

int prompt(void);
char *_reader(void);
char *_path(char **av, char *PATH);
int _forku(char **av, char *buff, char *path);
int builtinschecker(char **av, char *buff, int status);
int _is_whitespace(char c);
/* Path Finder */

char **tokenizer(char *buff);
int _splitter(char *s);
int _comparepath(const char *str1, const char *str2);
char *_completeconcat(char *str, char **av, char *token);

/* and some more functions */

char *_getenviron(const char *name);
int _environ(void);
void _puts(char *str);
int _putchar(char c);

#endif /* _MAIN_H_ */
