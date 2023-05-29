#include "main.h"

/**
* get_specified - finds the format func
* @s: the format string
* Return: the number of bytes printes
*/
int (*get_specified(char *s))(va_list ap, params_t *params)
{
specified_t specifiers[] = {
{"c", print_char},
{"d", print_int},
{"i", print_int},
{"s", print_string},
{"%", print_percent},
{"b", print_binary},
{"o", print_octal},
{"u", print_unsigned},
{"x", print_hex},
{"X", print_HEX},
{"p", print_address},
{"S", print_S},
{"r", print_rev},
{"R", print_rot13},
{NULL, NULL}
};
int j = 0;
while (specifiers[j].specified)
{
if (*s == specifiers[j].specified[0])
{
return (specifiers[j].fnc);
}
j++;
}
return (NULL);
}

/**
* get_print_func - finds the format fun
* @s: the format string
* @ap: argument pointer
* @params: the the parameters struct
* Return: the number of bytes printed
*/
int get_print_func(char *s, va_list ap, params_t *params)
{
int (*fnc)(va_list, params_t *) = get_specified(s);
if (fnc)
return (fnc(ap, params));
return (0);
}

/**
* get_flag - finds the flag func
* @s: the format string
* @params: the parameters struct
* Return: if flag was valid
*/
int get_flag(char *s, params_t *params)
{
int j = 0;
switch (*s)
{
case '+':
j = params->plus_flag = 1;
break;
case ' ':
j = params->space_flag = 1;
break;
case '#':
j = params->plus_flag = 1;
break;
case '-':
j = params->minus_flag = 1;
break;
case '0':
j = params->zero_flag = 1;
break;
}
return (j);
}

/**
* get_modifier - finds the modifier func
* @s: the format string
* @params: the parameters struct
* Return: if modifier was valid
*/
int get_modifier(char *s, params_t *params)
{
int j = 0;
switch (*s)
{
case 'h':
j = params->h_modifier = 1;
break;
case 'l':
j = params->l_modifier = 1;
break;
}
return (j);
}
/**
* get_width - gets the width from the format string
* @s: the format string
* @params: the parameters struct
* @ap: the argument pointer
* Return: new pointer
*/
char *get_width(char *s, params_t *params, va_list ap)
{
int i = 0;
if (*s == '*')
{
i = va_arg(ap, int);
s++;
}
else
{
while (_isdigit(*s))
i = i * 10 + (*s++ - '0');
}
params->width = d;
return (s);
}

