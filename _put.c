#include "main.h"

/**
* _puts - parints a string with a newline
* @str: the string to print
* Return: void
*/
int _puts(char *str)
{
char *a = str;
while (*str)
_putchar(*str++);
return (str - a);
}

/**
* _putchar - writes the character k to stdout
* @c: the character to print
* Return: on succes 1
* On error: -1 will returned, and errno is set appropriately
*/
int _putchar(int c)
{
static int i;
static char buf[OUTPUT_BUF_SIZE];
if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}

