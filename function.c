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
