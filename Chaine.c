#include "shell.h"

/**
 * _DupChaine - a function that duplicate a string
 * @chain: a string given.
 * Return: a pointer to a new string which is a duplicate of the
 * string.
 */
char *_DupChaine(const char *chain)
{
	char *p;
	int i, len = 0;

	if (chain == NULL)
		return (NULL);

	while (chain[len])
		len++;

	p = malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		p[i] = chain[i];
	return (p);
}

/**
  * _CompChain - a function that compares two strings
  * @chain1: a pointer to the first string
  * @chain2: a pointer to the second string
  * Return: integer
  */
int _CompChain(char *chain1, char *chain2)
{
	int comp;

	comp = (int)*chain1 - (int)*chain2;
	while (*chain1)
	{
		if (*chain1 != *chain2)
			break;
		chain1++;
		chain2++;
		comp = (int)*chain1 - (int)*chain2;
	}
	return (comp);
}

/**
  * _LongChain - a function that returns the length of a string
  * @chain: a pointer to a string
  * Return: the lenght of the string
  */
int _LongChain(char *chain)
{
	int longu = 0;

	while (chain[longu])
		longu++;
	return (longu);
}

/**
  * _ConChain - a function that concatenates two strings
  * @src: a pointer to source string
  * @dest: a pointer to dest string
  * Return: the src string appending to the dest string
  */
 
char *_ConChain(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dest);
}

/**
 *_CopChain - copies the string pointed to by src
 *@dest: A pointer to a char that will be changed
 *@src: A pointer to a char that will be changed
 *Return: dest
 */

char *_CopChain(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}