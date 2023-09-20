#include "shell.h"
/**
 * free_array - a function that frees an array of strings.
 * @tabl: the array to free.
 * Return: (void).
*/
void free_array(char **tabl)
{
	int i;

	if (!tabl)
		return;

	for (i = 0; tabl[i]; i++)
	{
		free(tabl[i]);
		tabl[i] = NULL;
	}
	free(tabl), tabl = NULL;
}
/**
 * print_error - a function that prints command not found error.
 * if command doesn't exist.
 * @name: shell name.
 * @idex: the command index.
 * @cmd: the command.
 * Return: (void).
*/
void print_error(char *name, int idex, char *cmd)
{
	char *index, mssg[] = ": not found\n";

	index = _IinToS(idex);

	write(STDERR_FILENO, name, _LongChain(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _LongChain(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _LongChain(cmd));
	write(STDERR_FILENO, mssg, _LongChain(mssg));
	free(index);
}

/**
 * print_cd_error - a function that prints can't cd error.
 * @name: shell name.
 * @idex: the command index.
 * @p: the non existing path.
 * Return: (void).
*/
void print_cd_error(char *name, int idex, char *p)
{
	char *index, mssg[] = ": cd: can't cd to ";

	index = _IinToS(idex);
	write(STDERR_FILENO, name, _LongChain(name));
	write(STDERR_FILENO, ": cd: ", 2);
	write(STDERR_FILENO, index, _LongChain(index));
	write(STDERR_FILENO, mssg, _LongChain(mssg));
	write(STDERR_FILENO, p, _LongChain(p));
	write(STDERR_FILENO, "\n", 1);

	free(index);
}

/**
 * set_wd_env - set environment for PWD and OLDPWD.
 * @env_key: environment key.
 * @env_value: environment value.
 * @new_env: new_environment variable.
 * Return: (void).
*/
void set_wd_env(char *env_key, char *env_value, char **new_env)
{
	int i;
	char *k, *var, *t, *new;

	for (i = 0; environ[i]; i++)
	{
		t = _DupChaine(environ[i]);
		k = strtok(t, "=");
		if (_CompChain(k, env_key) == 0)
		{
			var = strtok(NULL, "\n");
			if (_CompChain(var, env_value) == 0)
			{
				free(t);
				return;
			}
			_CopChain(environ[i], env_key);
			_ConChain(environ[i], "=");
			_ConChain(environ[i], env_value);
			free(t);
			return;
		}
		free(t), t = NULL;
	}
	new = malloc(_LongChain(env_key) + _LongChain(env_value) + 2);
	_CopChain(new, env_key);
	_ConChain(new, "=");
	_ConChain(new, env_value);
	environ[i] = new, environ[i + 1] = NULL;
	(*new_env) = new;
}
