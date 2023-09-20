#include "shell.h"


char *ligneDeLecture(void)
{
    char *ligne = NULL;
    size_t len = 0;
    ssize_t n;
    if (isatty(STDIN_FILENO))
        write (STDOUT_FILENO , "$ " , 2);
    n = getline (&ligne, &len, stdin);
    if (n == -1)
    {
        free (ligne);
        return (NULL);
    }
    return (ligne);
}