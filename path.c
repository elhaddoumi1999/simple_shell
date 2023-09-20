#include "shell.h"

/**
 * dir_list - a function that builds a linked list
 * of the PATH directories.
 * Return: a linked list of the PATH directories.
*/
list_dir *dir_list(void)
{
	list_dir *h = NULL;
	char *path_env, *t;

	path_env = _Env("PATH");
	if (!path_env)
		return (NULL);
	t = strtok(path_env, ":");
	while (t)
	{
		_add(&h, t);
		t = strtok(NULL, ":");
	}
	free(path_env);
	return (h);
}

/**
 * _path - a function that handle the path of a command.
 * @cmd: the command to handle.
 * Return: the full path of the command.
*/
char *_path(char *cmd)
{
	list_dir *ld, *tmp;
	char *p;
	struct stat st;
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/') 
		{
			if (stat(cmd, &st) == 0) 
				return (_DupChaine(cmd));
			return (NULL);
		}
	}
	ld = dir_list(); 
	tmp = ld;
	while (tmp)
	{
		p = malloc(_LongChain(tmp->dir) + _LongChain(cmd) + 2);
		if (!p)
		{
			_free(ld);
			return (NULL);
		}
		_CopChain(p, tmp->dir);
		_ConChain(p, "/");
		_ConChain(p, cmd);
		if (stat(p, &st) == 0)
		{
			_free(ld);
			return (p);
		}
		free(p), p = NULL;
		tmp = tmp->next;
	}
	_free(ld);
	return (NULL);
}
