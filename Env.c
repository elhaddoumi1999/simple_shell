#include "shell.h"

/**
 * _Env - a function used to retrieve the value of an environment variable.
 * @var: the name of the variable.
 * Return: the value of the environment variable.
*/
char *_Env(char *var)
{
	char *key, *tmp, *env;
	int j;

	for (j = 0; environ[j]; j++)
	{
		tmp = _DupChaine(environ[j]);
		key = strtok(tmp, "=");
		if (_CompChain(key, var) == 0)
		{
			env = _DupChaine(strtok(NULL, "\n"));
			free(tmp);
			return (env);
		}
		free(tmp);
	}

	return (NULL);
}
