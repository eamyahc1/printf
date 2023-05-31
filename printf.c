#include "main.h"

/**
* _printf - a function that prints anything
* @format: the format string
*
* Return: number of bytes printed
*/
int _printf(const char *format, ...)
{
int Sum = 0;
va_list ap;
const char *p, *start;
params_t params = PARAMS_INIT;

va_start(ap, format);

if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (p = (char *)format; *p; p++)
{
init_params(&params, ap);
if (*p != '%')
{
Sum += _putchar(*p);
continue;
}
start = p;
p++;
while (get_flag(p, &params)) /* while char ap p is a flag char */
{
p++; /*next char*/
}
p = get_width(p, &params, ap);
p = get_precision(p, &params, ap);
if (!get_specified(p))
Sum += print_from_to(start, p,
params.l_modifier || params.h_modifier ? p - 1 : 0);
else
Sum += get_print_func(p, ap, &params);
}
_putchar(BUFFER_FLUSH);
va_end(ap);
return (Sum);
}

