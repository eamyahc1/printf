#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
* struct parameters - parameters struct
*
* @unsign: flag if unsigned value
*
* @plus_flag: on when it is specified
* @space_flag: on when it is specified
* @hashtag_flag: on when it is specified
* @zero_flag: on when it is specified
* @minus_flag: on when it is specified
*
* @width: field width specified
* @precision: field precision specified
*
* @h_modifier: on when it is specified
* @l_modifier: on when it is specified
*
*/
typedef struct parameters
{
unsigned int unsign : 1;
unsigned int plus_flag : 1;
unsigned int space_flag : 1;
unsigned int hashtag_flag : 1;
unsigned int zero_flag : 1;
unsigned int minus_flag : 1;

unsigned int width;
unsigned int precision;

unsigned int h_modifier : 1;
unsigned int l_modifier : 1;
} params_t;

/**
 * struct specified - Struct token
 *
 * @specified: The format token
 * @fnc: The function associated.
 */
typedef struct specified
{
char *specified;
int (*fnc)(va_list, params_t *);
} specified_t;

/*_put.c module*/
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module*/
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_s(va_list ap, params_t *params);

/* number.c module*/
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* format.c module*/
int (*get_specified(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(const char *s, params_t *paramst);
int get_modifier(char *s, params_t *params);
int (*get_width(char *s, va_list ap, params_t *params));

/* convert_number.c module*/
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* simple_printers.c module*/
int print_form_to(char *start, char *stop, char *execute);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* print_number.c module*/
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* parameters.c module*/
void init_params(params_t *params, va_list ap);

/* string_fields.c module*/
char *get_percision(char *p, params_t *params, va_list ap);

/* _printf.c module*/
int _printf(const char *format, ...);

#endif
