#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>


char *sh_read_line(void);
char **sh_get_cmds(char *line);
int sh_run(char **cmds, char **argv);
char **_tokenize(char *str, char *delim);
char *_get_env(char *env, char *envp[]);
int envlen(char *envp[]);
void _puts(char *str);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
char *_strcat(char *strings[]);
int _strlen(char *str);
int _strs_len(char *strings[]);
int _strslen(char **strings);
int _pstrlen(char **strings);
char *cmd_exists(char *cmd);
int run_built_in(char *built_in, char **args);
void create_process(char *cmd, char **args);
int _bcd(char **dir);
int _bexit(char **status);
int _bhelp(char *);
void _benv(void);
char *int_tostr(int n);
int str_toint(char *str);
void get_num(int n, char *str,int index);
int _pow(int n, int e);
int ilen(int n);
char *_memset(char *s, char b, unsigned int n);
void ffree(char **pp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);



extern char **environ;
