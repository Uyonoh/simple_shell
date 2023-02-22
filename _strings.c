#include "main.h"
#define CAT_LEN 3

/**
 * _strcat - concatenate multiple strings
 * @strings: strings to concateneta
 *
 * Return: joined strings
 */

char *_strcat(char *strings[])
{
	int i;
	int j;
	int n;
	int len;
	char *str;

	i = 0;
	n = 0;
	len = CAT_LEN;
	str = malloc(sizeof(char) * _strslen(strings));

	if (!str)
	{
		fprintf(stderr, "malloc");
	}

	while (i < len)
	{
		for (j = 0; j < _strlen(strings[i]); j++, n++)
		{
			if (strings[i][j] != '\0' && strings[i][j] != '\n')
			{
				str[n] = strings[i][j];
			}
		}
		i++;
	}
	str[n] = '\0';
	return (str);
}


/**
 * _strlen - gets length of string
 * @str: string
 *
 * Return: (int)length of string
 */

int _strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}


/**
 * _strs_len - get the total length of multiple strings
 * @strings: strings
 *
 * Return: int - len
 */

int _strs_len(char *strings[])
{
	int i;
	int j;
	int n;


	i = 0;
	n = 0;
	while (strings[i])
	{
		printf("%d: %s\n", i, strings[i]);
		for (j = 0; j < _strlen(strings[i]); j++, n++)
		{
		}
		i++;
	}

	return (n);
}


/**
 * _strslen - get the total length of multiple strings
 * @strings: strings
 *
 * Return: int - len
 */

int _strslen(char *strings[])
{
	int i;
	int n;
	int j;
	int len;

	i = 0;
	n = 0;
	j = 0;
	len = CAT_LEN;
	while (i < len)
	{
		j = 0;
		while (strings[i][j])
		{
			j++;
			n++;
		}
		i++;
	}
	return (n);
}


/**
 * _pstrlen - returns the lenght of an array of arrays
 * @strings: arrays(strings)
 *
 * Return: int
 */

int _pstrlen(char **strings)
{
	int i = 0;

	while (strings[i])
	{
		if (strings[i] != NULL)
			i++;
	}
	return (i);
}
