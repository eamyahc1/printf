#include "main.h"

/**
 * print_from_to - imprime une plage d'adresses de caractères
 * @start: adresse de début
 * @stop: adresse de fin
 * @except: adresse à exclure
 * Return: le nombre d'octets imprimés
 */
int print_from_to(char *start, char *stop, char *except)
{
int S = 0;
while (start <= stop)
{
if (start != except)
S += _putchar(*start);
start++;
}
return (S);
}

/**
 * print_rev - imprime une chaîne de caractères à l'envers
 * @ap: la chaîne de caractères
 * @params: la structure des paramètres
 * Return: le nombre d'octets imprimés
 */
int print_rev(va_list ap, params_t *params)
{
int len, S = 0;
char *str = va_arg(ap, char *);
(void)params;

if (str)
{
for (len = 0; *str; str++)
len++;
str--;

for (; len > 0; len--, str--)
S += _putchar(*str);
}

return (S);
}

/**
 * print_rot13 - imprime une chaîne de caractères en rot13
 * @ap: la chaîne de caractères
 * @params: la structure des paramètres
 * Return: le nombre d'octets imprimés
 */
int print_rot13(va_list ap, params_t *params)
{
int i, index;
int count = 0;
char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
char *a = va_arg(ap, char *);
(void)params;

i = 0;
index = 0;

while (a[i])
{
if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
{
index = a[i] - 65;
count += _putchar(arr[index]);
}
else
{
count += _putchar(a[i]);
}
i++;
}
return (count);
}

