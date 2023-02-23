#include "main.h"
#define LINE_BUFFER 100

/**
 * sh_read_line - reads a line from stdin
 *
 * Return: void
 */

char *sh_read_line(void)
{
	int c;
	char *line;
	int old_buffer;
	int line_buffer;
	int i, rd;

	line_buffer = LINE_BUFFER;
	line = malloc(sizeof(char) * line_buffer);
	i = 0;
	while (1)
	{
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (c == EOF || c == '\n')
		{
			if (i == 0)
			{
				return (NULL);
			}
			return (line);
		}
		line[i] = c;
		i++;
		/* if index outside line, reallocate memory to line */
		if (i >= line_buffer)
		{
			old_buffer = line_buffer * sizeof(char);
			line_buffer += LINE_BUFFER;
			line = _realloc(line, old_buffer, sizeof(char) * line_buffer);
			if (!line)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
		}
	}
}
