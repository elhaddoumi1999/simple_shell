#include "shell.h"
/**
 * _fileInput - get input from file.
 * @av: arguments.
 * Return: a struct file_input contains datas of input.
*/
file_input _fileInput(char **av)
{
	int fd, r, i = 0;
	char avant[4096], *ligne = NULL;
	char msseg[] = ": 0: Can't open ";
	file_input data;

	data.len = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, av[0], _LongChain(av[0]));
		write(STDERR_FILENO, msseg, _LongChain(msseg));
		write(STDERR_FILENO, av[1], _LongChain(av[1]));
		write(STDERR_FILENO, "\n", 1);
		exit(127);
	}
	r = read(fd, avant, 4095);
	if (r <= 0)
		return (data);
	avant[r] = '\0';

	ligne = strtok(avant, "\n");
	while (ligne)
	{
		data.lines[i] = _DupChaine(ligne);
		ligne = strtok(NULL, "\n");
		i++;
		data.len++;
	}
	close(fd);
	return (data);
}
