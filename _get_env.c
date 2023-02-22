#include "main.h"

/**
 * _get_env - get environment variable
 * @env: env variable of interest
 * @envp: env variables
 *
 * Return: env_var
 */

char *_get_env(char *env, char *envp[])
{
	int i;
	int j;
	int index;

	/* index - start pos for return str(after '=') */
	index = strlen(env) + 1;
	/* strbuffer = STRBUFFER; */
	/* env_str = malloc(sizeof(char) * strbuffer); */

	for (i = 0; i < envlen(envp); i++)
	{
		for (j = 0; j < _strlen(env); j++)
		{
			if (env[j] == envp[i][j])
			{
				continue;
			} else
			{
				break;
			}
		}
		if (!env[j])
		{
			return (envp[i] + index);
		}
	}
	return (NULL);
}


/**
 * envlen - Get the length of the environment variable
 * @envp: environment variables
 * Return: length of envp
 */

int envlen(char *envp[])
{
	int i;

	i = 0;
	while (envp[i])
	{
		i++;
	}

	return (i);
}
