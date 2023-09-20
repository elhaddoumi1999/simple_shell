#include "shell.h"
/**
 * _comments - a function that handle shell comments
 * @comnd: the command
 * Return: (void)
*/
void _comments(char ***comnd)
{
	int i, commit = 0;

	if (!(*comnd))
		return;

	for (i = 0; (*comnd)[i]; i++)
	{
		if ((*comnd)[i][0] == '#')
		{
			commit = 1;
			break;
		}
	}
	if (commit)
	{
		while ((*comnd)[i])
		{
			free((*comnd)[i]), (*comnd)[i] = NULL;
			i++;
		}
	}
	if (!(*comnd)[0])
	{
		free((*comnd)), (*comnd) = NULL;
	}
}
