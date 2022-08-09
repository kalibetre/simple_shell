#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 * struct list_t - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_t
{
	char *str;
	struct list_t *next;
} list_s;

/**
 * struct Env_s - singly linked list for Env Vars
 * @key: string - (malloc'ed string) of the key
 * @value: string - (malloc'ed string) of the value
 * @next: points to the next node
 *
 * Description: singly linked list node structure for Env
 */
typedef struct Env_s
{
	char *key;
	char *value;
	struct Env_s *next;
} EnvList;

/**
 * struct BuiltIn_s - BuiltIn function
 * @name: string - the name of function
 * @func: function pointer
 *
 * Description: a BuiltIn functions structure
 */
typedef struct BuiltIn_s
{
	char *name;
	int (*func)(char *, char **, int, EnvList **);
} BuiltIn;

void run_shell(char **argv, char **env);
int execute_input(char **argv, char *input, int cmd_num, EnvList **env_ls);
int run_child_process(char **command, EnvList **env_ls);
ssize_t _getline(char **line);
char *_realloc(char *str, int size);

/* strtok */
char *_strtok(char *str, const char *delim);
void skip_delim(char **str, char delim);
int count_until_delim(char *str, const char *delim);

/* Array Helpers */
char **str_ary_dup(char **ary, size_t start_index, size_t count);
void free_str_ary(char **ary);
int count_tokens(char *str, char delim);
char **str_to_ary(char *str, const char *delim, int *size);

/* String List Helpers */
void free_str_list(list_s *list);
list_s *add_to_str_list(list_s **head, const char *str);
list_s *str_to_str_list(char *str, const char *delim);

/* Path Helpers */
char *make_path(char *parent_dir, char *file_name);
char *find_in_path(char *file, EnvList *env_ls);

/* Print Helpers */
int _putchar(char c);
int _putchar_er(char c);
void _print(char *str);
void _puts(char *str);
void _puts_mul(int count, ...);

/* Error */
void print_error(char *shell, int num, char *command, char *message);
void print_err_number(int n);

/* String Helpers */
size_t _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

int _atoi(char *str);

#endif
