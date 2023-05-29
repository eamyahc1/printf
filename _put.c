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
* @k: the character to print
* Return: on succes 1
* On error: -1 will returned, and errno is set appropriately
*/
int _putchar(int k)
{
static int j;
static char buf[OUTPUT_BUFFER_SIZE];
if (k == BUFFER_FLUSH || j >= OUTPUT_BUFFER_SIZE)
{
write(1, buf, j);
j = 0;
}
if (k != BUFFER_FLUSH)
buf[j++] = k;
return (1);
}

