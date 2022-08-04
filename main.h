#ifndef SIMPLESHELL_H 
#define SIMPLESHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>                                                 
#include <sys/wait.h>
#include <sys/stat.h>
extern char **environ;
int create_child(char **argv);
int create_child2(char **argv, char *path);
void tokenizer(char *buffer, char **array, char *delim);
void init(char **array);
int check_space(char *buffer);
char *_getenv(const char *name);
void get_path(char **array_dir);
void free_array_dir(char **arry_dir);
char *check_path(char *buffer, char **array_path);
int check_stat(char *argv);
int check_dir(char *array);
#endif
