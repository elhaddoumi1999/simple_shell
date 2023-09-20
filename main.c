#include "shell.h"

/**
 * main - Simple Shell main function.
 * @ac: argumnents counter.
 * @av: Arguments.
 * Return: the status of last execute.
 */

int main(int ac, char **av)
{
	int statut = 0, index = 0, L = 1, i = 0;
	char *ligne = NULL, **comnd = NULL, *new_env = NULL;
	file_input data;

	if (ac == 2)
	{
		data = _fileInput(av);
		L = data.len;
	}
	while (L)
	{
		if (ac == 2)
		{
			L--;
			ligne = data.lines[i++];
		}
		else
			ligne = ligneDeLecture();
		if (ligne == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(new_env);
			return (statut);
		}
		index++;
		comnd = Fractio_Ligne(ligne);
		_comments(&comnd);
		if (!comnd)
			continue;
		R_variable(comnd, statut);

		if (if_builtin(comnd[0]))
			handle_builtin(comnd, av, &statut, index, &new_env);
		else
			statut = _Run(comnd, av, index);
	}
	return (0);
}
