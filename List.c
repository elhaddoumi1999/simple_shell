#include "shell.h"

/**
 * _add - a function that adds a new node at the end
 * of a list_dir list.
 * @H: a list_dir list.
 * @chain: the element to add.
 * Return: the address of the new element, or NULL if it faile.
 */
list_dir *_add(list_dir **H, const char *chain)
{
	list_dir *N, *T;

	if (H == NULL || chain == NULL)
		return (NULL);

	N = malloc(sizeof(list_dir));
	if (N == NULL)
		return (NULL);

	N->dir = _DupChaine(chain);
	if (N->dir == NULL)
	{
		free(N);
		return (NULL);
	}
	N->next = NULL;
	if (*H == NULL)
	{
		*H = N;
		return (*H);
	}
	T = *H;
	while (T->next != NULL)
		T = T->next;

	T->next = N;
	return (*H);
}

/**
 * _free - Frees a list_dir list
 * @H: Start of the list
 * Return: (void)
 */
void _free(list_dir *H)
{
	list_dir *T;

	if (H == NULL)
		return;
	while (H != NULL)
	{
		T = H->next;
		free(H->dir);
		free(H);
		H = T;
	}
}
