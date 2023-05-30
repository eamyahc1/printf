#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @ap: the rgument pointer
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
int n = 0;
if (*p != '.')
return (p);
p++;
if (*p == '*')
{
n = va_arg(ap, int);
p++;
}
else
{
while (_isdigit(*p))
n = n * 10 + (*p++ - '0');
}
params->precision = n;
return (p);
}

