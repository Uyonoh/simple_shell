#include "main.h"

/**
 * sh_run - exectues the given command
 * @args: command input
 * @argv: main args variables
 *
 * Return: 1 or 0
 */

int sh_run(char **args, char **argv)
{
	int status;
	char *cmd;

	if (args == NULL)
	{
		return (1);
	}

	cmd = args[0];

	/* check builtins for command */
	status = run_built_in(args[0], args);
	if (status != -1)
	{
		/* cmd in built ins */
		return (status);
	}

	/* check if command exists in path */
	cmd = cmd_exists(cmd);
	if (!cmd)
	{
		/* if cmd does not exist return to prompt */
		perror(argv[0]);
		return (1);
	}

	/* create child process, execute command and return to prompt */
	create_process(cmd, args);
	return (1);
}


/**
 * cmd_exists - check if a command/file exists
 * @cmd: command or file name
 *
 * Return: path of command/file
 */

char *cmd_exists(char *cmd)
{
	int i;
	char *env_path;
	char *env_cpy;
	char **path;
	char *_path;
	char *catstrs[3];
	struct stat info;

	if (cmd != NULL)
	{

		env_path = _get_env("PATH", environ);
		env_cpy = malloc(sizeof(char) * _strlen(env_path) + 1);
		strcpy(env_cpy, env_path);
		path = _tokenize(env_cpy, ":");

		if (cmd[0] == '/')
		{
			/* command is a full path */
			if (stat(cmd, &info) != 0)
			{
				/* If file does not exist, return to prompt */
				return (NULL);
			}
			return (cmd);
		}

		for (i = 0; i < _pstrlen(path); i++)
		{
			catstrs[0] = path[i];
			catstrs[1] =  "/";
			catstrs[2] = cmd;

			_path = _strcat(catstrs);
			if (stat(_path, &info) == 0)
			{
				return (_path);
			}
			free(_path);
		}
	}
	return (NULL);
}


/**
 * create_process - create a child process and execute a command
 * @cmd: command
 * @args: arguments to command
 *
 *Return: void
 */

void create_process(char *cmd, char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		/*  within child process */
		if (execve(cmd, args, NULL) == -1)
		{
			/* execution error */
			perror(cmd);
		}
	} else if (pid < 0)
	{
		/* forking error */
		perror("fork");
	} else
	{
		/* within parent process */
		/* wait for child process */
		wait(&status);
	}
}
