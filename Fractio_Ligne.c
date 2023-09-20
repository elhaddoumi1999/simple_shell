#include "shell.h"

/**
 * Fractio_Ligne - a functin that splits a string into tokens.
 * @ligne: the string to split.
 * Return: a null terminating array of strings, containing each word of line
 * or null if line is only delimiters.
*/
char **Fractio_Ligne(char *ligne)
{
	int x = 0, c = 0;
	char *t, *tmp, **array = NULL;

	if (ligne == NULL)
		return (NULL);

	tmp = _DupChaine(ligne); 
	t = strtok(tmp, DELIM); 
	if (!t) 
	{
		free(ligne), ligne = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (t) 
	{
		c++;
		t = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	
	array = malloc(sizeof(char *) * (c + 1));
	if (!array)
	{
		free(ligne), ligne = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	t = strtok(ligne, DELIM);
	while (t)
	{
		array[x++] = _DupChaine(t);
		t = strtok(NULL, DELIM); 
	}
	array[x] = NULL;
	free(ligne), ligne = NULL;

	return (array);
}