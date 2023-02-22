#include "main.h"

/**
 * run_built_in - exectues builtin commands
 * @built_in: command
 * @args: command arguments
 *
 * Return: 1 or 0 or -1
 */

int run_built_in(char *built_in, char **args)
{
	int i;
	int status;
	int (*_builtins[])() = {_bcd, _bhelp, _bexit};
	char *_built_ins[] = {"cd", "help", "exit", NULL};
	void (*void_builtins[])() = {_benv};
	char *void_built_ins[] = {"env", NULL};

	i = 0;
	status = -1;
	while (_built_ins[i] != NULL)
	{
		if (_strcmp(built_in, _built_ins[i]) == 0)
		{
			status = _builtins[i](args);
			return (status);
		}
		i++;
	}

	i = 0;
	while (void_built_ins[i] != NULL)
	{
		if (_strcmp(built_in, void_built_ins[i]) == 0)
		{
			void_builtins[i]();
		}
		i++;
	}

	return (status);
}

/**
 * _bexit - builtin exit
 * @status: (int)exit status
 *
 * Return: 0 or 1
 */

int _bexit(char **status)
{
	int _status;

	if (!status[1])
	{
		_status = 0;
	} else
	{
		_status = str_toint(status[1]);
	}

	return (_status);

	/**
	* pid = getpid();
	* _pid = int_tostr(pid);
	* char *args[] = {"kill", _pid};
	* printf("%s\n", environ[13]);
	* printf("%d\n", pid);
	* sh_run(args);
	* return (1);
	*/
}


/**
 * _bcd - builtin cd
 * @dir: new directory
 *
 * Return: 1 or -1
 */

int _bcd(char **dir)
{
	char *prevd;

	if (_pstrlen(dir) == 2)
	{

		if (dir[1][0] == '-')
		{
			prevd = _get_env("OLDPWD", environ);
			chdir(prevd);
			return (1);
		}

		if (chdir(dir[1]) == 0)
		{
			return (1);
		}
		perror("cd");
	} else if (_pstrlen(dir) > 2)
	{
		_puts("string not in pwd: ");
	} else if (_pstrlen(dir) == 1)
	{
		chdir("$HOME");
	}

	return (1);
}

/**
 * _bhelp - builtin help
 * @cmd: command
 *
 * Return: 1
 */

int _bhelp(char *cmd)
{
	printf("help %s\n", cmd);
	return (1);
}

/**
 * _benv - prints the current environment
 *
 * Return: void
 */

void _benv(void)
{
	int i;

	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
