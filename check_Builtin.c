#include "shell.h"

/**
 * if_builtin - check if a command is builtin.
 * @cmd: the command to check.
 * Return: 1 if the command is builtin otherwise 0.
*/
int if_builtin(char *cmd)
{
	int i;
	char *bui[] = {
		"exit", "env", "setenv",
		"unsetenv", "cd",
		NULL
	};

	for (i = 0; bui[i]; i++)
	{
		if (_CompChain(cmd, bui[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * handle_builtin - handle builtin.
 * @cmd1: the builtin command.
 * @av: arguments.
 * @statut: exit status.
 * @idex: index of the command.
 * @new_env: new_environment variable.
 * Return: 1 if the command is builtin otherwise 0.
*/
void handle_builtin(char **cmd1, char **av, int *statut, int idex, char **new_env)
{
	int i;
	bui B[] = {
		/*{"exit", _exit},*/
		{"env", _print},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"cd", change_directory},
		{NULL, NULL}
	};

	for (i = 0; B[i].builtin; i++)
	{
		if (_CompChain(B[i].builtin, cmd1[0]) == 0)
		{
			B[i].f(cmd1, av, statut, idex, new_env);
			break;
		}
	}
}

/**
 * _exit - exit builtin
 * this function exits the shell whith status
 * @comnd: the builtin command.
 * @av: arguments.
 * @statut: exit status.
 * @idex: index of the command.
 * @new_env: new_environment variable.
 * Return: (void)
*/
/*void _exit(char **comnd, char **av, int *statut, int idex, char **new_env)
{
	int exit_statut = (*statut);

	char *index, mssg[] = ": exit: Illegal number: ";

	if (comnd[1])
	{
		if (!if_positive_number(comnd[1]))
		{
			index = _IinToS(idex);
			write(STDERR_FILENO, av[0], _LongChain(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, _LongChain(index));
			write(STDERR_FILENO, mssg, _LongChain(mssg));
			write(STDERR_FILENO, comnd[1], _LongChain(comnd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(index), free_array(comnd), free((*new_env));
			(*statut) = 2;
			return;
		}
		else
			exit_statut = _StoI(comnd[1]);
	}
	free_array(comnd), free((*new_env));
	exit(exit_statut);
}*/

/**
 * _print - print environement variables
 * @comnd: the builtin command.
 * @av: arguments.
 * @statut: exit status.
 * @idex: index of the command.
 * @new_env: new_environment variable.
 * Return: (void)
*/
void _print(char **cmnd, char **av, int *statut, int idex, char **new_env)
{
	int i;
	(void) av;
	(void) idex;
	(void) new_env;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _LongChain(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	(*statut) = 0;
	free_array(cmnd);
}
