#include "shell.h"

/**
 * _Run - a function for running a command.
 * @cmd: the command to be executed.
 * @av: arguments for the command.
 * @index: index of the command.
 * Return: the exit status of the child process
 * or 127 if the command is not found.
*/

int _Run(char **cmd, char **av, int index)
{
	pid_t ch;
	char *cmd2;
	int statut;

	cmd2 = _path(cmd[0]);

	if (!cmd2)  
	{
		print_error(av[0], index, cmd[0]);
		free_array(cmd);
		return (127);
	}
	ch = fork();
	if (ch == 0)
	{
		if (execve(cmd2, cmd, environ) == -1)
		{
			free_array(cmd);
			free(cmd2), cmd2 = NULL;
		}
	}
	else
	{
		waitpid(ch, &statut, 0);
		free_array(cmd);
		free(cmd2), cmd2 = NULL;
	}

	return (WEXITSTATUS(statut));
	
}
