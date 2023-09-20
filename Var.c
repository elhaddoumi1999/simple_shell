#include "shell.h"
/**
 * R_variable- variable replacement.
 * @comnd: the current command.
 * @statut: the exit status of the last command.
 * Return: (void)
*/
void R_variable(char **comnd, int statut)
{
	int i;
	char *R = NULL, *chain, c;

	for (i = 0; comnd[i]; i++)
	{
		if (comnd[i][0] == '$')
		{
			c = comnd[i][1];
			if (c == '?')
				R = _IinToS(statut);

			else if (c == '$')
				R = _IinToS((int) getpid());
			else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			{
				chain = comnd[i];
				chain++;
				R = _Env(chain);
				if (!R)
					R = _DupChaine("");
			}
			if (R)
				free(comnd[i]), comnd[i] = R;
		}
	}
}
