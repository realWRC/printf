#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * _strlen - Function that returns the length of a string
 * @s: String feed to the function
 * Return: Length of string
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
/**
 * print_int - Function that prints an integer with write function
 * @integer: Integer to be printed
 * Return: Number of printed characters for the interger
 */
int print_int(int integer)
{
	int size = snprintf(NULL, 0, "%d", integer);
	char *container;

	container = (char *)malloc((size + 1) * sizeof(char));
	if (container == NULL)
	{
		free(container);
		exit(EXIT_FAILURE);
	}
	snprintf(container, size + 1, "%d", integer);
	write(1, container, size);
	free(container);
	return (size);
}
/**
 * _putchar - Function that prints a single character
 * @c: Character to be printed
 * Return: Always (1) on success
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
