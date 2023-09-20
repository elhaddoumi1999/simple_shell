#include "shell.h"

/**
 * if_positive_number - check if a string is positive number.
 * @chain: the string to check.
 * Return: 1 if the string is a positive number
 * otherwise 0.
*/
int if_positive_number(char *chain)
{
	int i;

	if (!chain)
		return (0);
	for (i = 0; chain[i]; i++)
	{
		if (chain[i] < '0' || chain[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _StoI - convert a string to an integer.
 * @chain: the string.
 * Return: numerical value of the string.
*/
int _StoI(char *chain)
{
	int i, num = 0;

	for (i = 0; chain[i] ; i++)
	{
		num *= 10;
		num += (chain[i] - '0');
	}
	return (num);
}

/**
 * reverse_string - a function that reverse string.
 * @chain: string to reverse.
 * @long1: the length of the string.
 * Return: (void).
*/
void reverse_string(char *chain, int long1)
{
	char tmp;
	int start = 0;
	int end = long1 - 1;

	while (start < end)
	{
		tmp = chain[start];
		chain[start] = chain[end];
		chain[end] = tmp;
		start++;
		end--;
	}
}

/**
 * _IinToS - convert an integer to string.
 * @n: the integer.
 * Return: string.
*/
char *_IinToS(int n)
{
	char avant[20];
	int i = 0;

	if (n == 0)
		avant[i++] = '0';
	else
	{
		while (n > 0)
		{
			avant[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	avant[i] = '\0';
	reverse_string(avant, i);

	return (_DupChaine(avant));
}
