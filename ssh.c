#include "main.h"

/**
 * main - Entry point for shell
 * @argc: no of arguments
 * @argv: arguments
 *
 * Return: 0
 */

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
	char *line;
	char **cmds;
	int status;

	status = 1;
	do {
		if (isatty(STDIN_FILENO))
		{
			_putchar('$');
			_putchar(' ');
		}
		line = sh_read_line();

		if (!line)
		{
			continue;
		}

		cmds = _tokenize(line, " ");
		status = sh_run(cmds);
	} while (status == 1);

	_exit(status);
}
