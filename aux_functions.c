#include "main.h"
/**
* create_child - generates a child process
* @argv : pointer to pointer
* Return : 0 or -1 on failure
*/
int create_child(char **argv)
{
	int status = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		execve(argv[0], argv, NULL);
	else
		wait(&status);
	return (0);
}
#include "main.h"
/**
* tokenizer - generates an array with the arguments given
* @buffer : the command line
* @array : pointer of pointer
* @delim : the arguments delimiter
* Return : nothing
*/
void tokenizer(char *buffer, char **array, char *delim)
{
	int i = 0;

	array[i] = strtok(buffer, delim);
	while (array[i])
	{
		i++;
		array[i] = strtok(NULL, delim);
	}
}
#include "main.h"
/**
* check_space - checks for a space in all the arguments
* @buffer : the command typed
* Return : 0 on failure, 1 on succes
*/
int check_space(char *buffer)
{
	int i = 0;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\t')
			return (1);
	}
	return (0);
}
#include "main.h"
/**
* _getenv - gives the enviromental variable depending the command typed
* @name : what the user typed
* Return : NULL or copy on success.
*/
char *_getenv(const char *name)
{
	char *copy = NULL;
	int i = 0;
	int count = strlen(name);

	for (; environ[i]; i++)
	{
	if (strncmp(environ[i], name, count) == 0)
	{
		copy = environ[i];
		return (copy);
	}
	}
	return (NULL);
}
#include "main.h"
/**
* get_path - path of typed arguments
* @array_dir : direction of array
* Return : nothing
*/
void get_path(char **array_dir)
{
	int i = 0;
	char *copy = NULL;
	char *dir = NULL;

	copy = strdup(_getenv("PATH="));
	strtok(copy, ":=");
	dir = strtok(NULL, ":=");

	if (dir)
	{
	for (i = 0; dir[i]; i++)
	{
		dir = strtok(NULL, ":=");
		array_dir[i] = strdup(dir);
	}
	array_dir[i] = NULL;
	free(copy);
	}
}
