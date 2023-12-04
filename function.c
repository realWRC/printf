#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * _strlen - function that returns the length of a string
 * @s: string feed to the function
 * Return: length of string
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
 * print_int - function that prints an integer with write function
 * @integer: Integer to be printed
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
