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
	char *argstr;
	char argchar;
	int i = 0;
	int j = 0;

	va_start(str, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					argchar = (char)va_arg(str, int);
					j += _putchar(argchar);
					break;
				case 's':
					argstr = va_arg(str, char *);
					write(1, argstr, sizeof(char) * _strlen(argstr));
					j += _strlen(argstr);
					break;
				default:
					j += _putchar('%');
					break;
			}
			i++;
		}
		else
			j += _putchar(format[i]);
		i++;
	}
	va_end(str);
	return (j);
}
