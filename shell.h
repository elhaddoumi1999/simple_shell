#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define DELIM " \n\t"
#define PROMPT "$ "

extern char **environ;



typedef struct list_dir
{
	char *dir;
	struct list_dir *next;
} list_dir;



typedef struct file_input
{
	char *lines[1024];
	int len;
} file_input;


typedef struct bui
{
	char *builtin;
	void (*f)(char **, char **, int*, int, char**);
} bui;


 char *ligneDeLecture(void);
 
 char *_DupChaine(const char *chain);
 int _CompChain(char *chain1, char *chain2);
 int _LongChain(char *chain);
 char *_ConChain(char *dest, char *src);
 char *_CopChain(char *dest, char *src);

 char **Fractio_Ligne(char *ligne);

 int _Run(char **cmd, char **argv, int index);

 char *_Env(char *var);

 void _comments(char ***comnd);

 void R_variable(char **comnd, int statut);

 int _Run(char **cmd, char **av, int index);

 file_input _fileInput(char **av);

 int if_builtin(char *cmd);
 void handle_builtin(char **cmd1, char **av, int *statut, int idex, char **new_env);
 void _exit(char **comnd, char **av, int *statut, int idex, char **new_env);
 void _print(char **cmnd, char **av, int *statut, int idex, char **new_env);

 void change_directory(char **comnd, char **av, int *statut, int idex, char **new_env);
 void _unsetenv(char **comnd, char **av, int *statut, int idex, char **new_env);
 void _setenv(char **comnd, char **av, int *statut, int idex, char **new_env);

 char *_path(char *cmd);
 list_dir *dir_list(void);

 void free_array(char **tabl);
 void print_error(char *name, int idex, char *cmd);
 void print_cd_error(char *name, int idex, char *p);
 void set_wd_env(char *env_key, char *env_value, char **new_env);

 char *_IinToS(int n);
 void reverse_string(char *chain, int long1);
 int _StoI(char *chain);
 int if_positive_number(char *chain);

 void _free(list_dir *H);
 list_dir *_add(list_dir **H, const char *chain);

 char *_path(char *cmd);

#endif