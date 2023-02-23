#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: pointer 1
 * @s2: pointer 2
 * Return: result
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		s1++;
		s2++;
	}
	return (0);
}


/**
 * _puts - print a string to stdout.
 * @str: string
 *
 * Return: void
 */

void _puts(char *str)
{
	int i;

	i = 0;
	while (i >= 0)
	{
		if (str[i] != '\0')
		{
			_putchar(str[i]);
			i++;
		} else
		{
			break;
		}
	}
	_putchar('\n');
}

