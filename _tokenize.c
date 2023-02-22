#include "main.h"
#define TOKENS_BUFFER 100


/**
 * _tokenize - splits a string by a dellimiter
 * @str: string
 * @delim: dellimiter
 *
 * Return: array of split strngs
 */

char **_tokenize(char *str, char *delim)
{
	char *token;
	char **tokens;
	int tokens_buffer;
	int old_buffer;
	int i;

	tokens_buffer = TOKENS_BUFFER;
	tokens = malloc(sizeof(char) * tokens_buffer);

	token = strtok(str, delim);

	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, delim);

		if (i >= tokens_buffer)
		{
			old_buffer = tokens_buffer * sizeof(char);
			tokens_buffer += TOKENS_BUFFER;
			tokens = _realloc(tokens, old_buffer, sizeof(char) * tokens_buffer);

			/* check for allocation error */
			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	tokens[i] = '\0';

	return (tokens);
}
