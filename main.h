#ifndef SIMPLESHELL_H 
#define SIMPLESHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>                                                 
#include <sys/wait.h>
#include <sys/stat.h>
int check_stat(char *argv, char *av);
int create_child(char **argv);
void tokenizer(char *buffer, char **array, char *delim);
void init(char **array);
int check_space(char *buffer);
#endif
