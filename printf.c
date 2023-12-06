#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Function that prints a formated string
 * @format: String to be formated
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list str;
	int i, j;

	if (format == NULL)
		return (0);
	 va_start(str, format);
	for (i = 0, j = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					j += char_sp((char)va_arg(str, int));
					break;
				case 's':
					j += string_sp(va_arg(str, char *));
					break;
				case 'd':
				case 'i':
					j += print_int(va_arg(str, int));
					break;
				case '%':
					j += _putchar('%');
					break;
				case '\0':
					break;
				default:
					defaultcase(format[i + 1]);
					break;
			}
			i++;
		}
		else
			j += _putchar(format[i]);
	}
	va_end(str);
	return (j);
}
/**
 * defaultcase - Abstraction for default in switch statement for
 * betty complince
 * @c: Default outputs
 * Return: Always (2) on success
 */
int defaultcase(char c)
{
	int count = 0;
	char argchar = c;

	count += _putchar('%');
	count += _putchar(argchar);
	return (count);
}
