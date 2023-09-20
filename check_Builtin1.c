#include "shell.h"
/**
 * _setenv - Initialize a new environment variable,
 * or modify an existing one.
 * @comnd: the builtin command.
 * @av: arguments.
 * @statut: exit status.
 * @idex: index of the command.
 * @new_env: new_environment variable.
 * Return: (void)
*/
void _setenv(char **comnd, char **av, int *statut, int idex, char **new_env)
{
	int i;
	char *k, *var, *t, *new;
	(void) idex;
	(void) av;

	if (!comnd[1] || !comnd[2])
	{
		free_array(comnd), (*statut) = 0;
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		t = _DupChaine(environ[i]);
		k = strtok(t, "=");
		if (_CompChain(k, comnd[1]) == 0)
		{
			var = strtok(NULL, "\n");
			if (_CompChain(var, comnd[2]) == 0)
			{
				free(t), free_array(comnd), (*statut) = 0;
				return;
			}
			_CopChain(environ[i], comnd[1]);
			_ConChain(environ[i], "=");
			_ConChain(environ[i], comnd[2]);
			free(t), free_array(comnd), (*statut) = 0;
			return;
		}
		free(t), t = NULL;
	}
	new = malloc(_LongChain(comnd[1]) + _LongChain(comnd[2]) + 2);
	_CopChain(new, comnd[1]);
	_ConChain(new, "=");
	_ConChain(new, comnd[2]);
	environ[i] = new, environ[i + 1] = NULL;
	(*new_env) = new;
	(*statut) = 0, free_array(comnd);
}
/**
 * _unsetenv - Remove an environment variable.
 * @comnd: the builtin command.
 * @av: arguments.
 * @statut: exit status.
 * @idex: index of the command.
 * @new_env: new_environment variable.
 * Return: (void)
*/
void _unsetenv(char **comnd, char **av, int *statut, int idex, char **new_env)
{
	int i;
	char *t, *k;
	(void) idex;
	(void) av;
	(void) new_env;

	if (comnd[1])
	{
		for (i = 0; environ[i]; i++)
		{
			t = _DupChaine(environ[i]);
			k = strtok(t, "=");
			if (_CompChain(comnd[1], k) == 0)
			{
				free(t), t = NULL;
				break;
			}
			free(t), t = NULL;
		}
		while (environ[i])
		{
			environ[i] = environ[i + 1];
			i++;
		}
	}
	(*statut) = 0;
	free_array(comnd);
}

/**
 * change_directory - change directory to given path.
 * @comnd: the builtin command.
 * @av: arguments.
 * @statut: exit status.
 * @idex: index of the command.
 * @new_env: new_environment variable.
 * Return: (void)
*/
void change_directory(char **comnd, char **av, int *statut, int idex, char **new_env)
{
	char *HOME, *OLDPWD, current_wd[1024];

	getcwd(current_wd, 1024);
	if (!comnd[1])
	{
		HOME = _Env("HOME");
		if (!HOME)
		{
			free_array(comnd), (*statut) = 0;
			return;
		}
		chdir(HOME), set_wd_env("PWD", HOME, new_env);
		free(HOME);
	}
	else if (_CompChain(comnd[1], "-") == 0)
	{
		OLDPWD = _Env("OLDPWD");
		if (!OLDPWD)
		{
			write(STDOUT_FILENO, current_wd, _LongChain(current_wd));
			write(STDOUT_FILENO, "\n", 1);
			free_array(comnd), (*statut) = 0;
			return;
		}
		chdir(OLDPWD), set_wd_env("PWD", OLDPWD, new_env);
		write(STDOUT_FILENO, OLDPWD, _LongChain(OLDPWD));
		write(STDOUT_FILENO, "\n", 1);
		free(OLDPWD);
	}
	else if (chdir(comnd[1]) == -1)
		print_cd_error(av[0], idex, comnd[1]);
	else
		set_wd_env("PWD", comnd[1], new_env);

	free_array(comnd), (*statut) = 0;
	set_wd_env("OLDPWD", current_wd, new_env);
}
