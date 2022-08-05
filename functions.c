#include "main.h"
/**
* free_array_dir - frees array direction
* @array_dir : array direction
* Return: nothing
*/
void free_array_dir(char **array_dir)
{
	int j = 0;

	if (array_dir)
	{
	for (j = 0; array_dir[j]; j++)
	free(array_dir[j]);
	}
}
#include "main.h"
/**
* check_dir - checks array direction
* @array : arr
* Return : 1 on success
*/
int check_dir(char *array)
{
	int i = 0;

	for (i = 0; array[i]; i++)
	{
	if (array[i] == '/')
		return (1);
	}
	return (0);
}
#include "main.h"
/**
* check_path - checks the current path
* @buffer : buff
* @array_path : arrays path
* Return : the dir if exists, NULL otherwise
*/
char *check_path(char *buffer, char **array_path)
{
	struct stat st;
	int i = 0;
	char *dir = NULL;

	for (i = 0; array_path[i]; i++)
	{
		dir = malloc(strlen(buffer) + strlen(array_path[i]) + 1000);
		if (dir == NULL)
			return (NULL);
		strcpy(dir, array_path[i]);
		strcat(dir, "/");
		strcat(dir, buffer);
		if (stat(dir, &st) == 0)
		{
			return (dir);
		}
		else
	free(dir);
	}
	return (NULL);
}
#include "main.h"
/**
* create_child2 - creates another child process
* @argv : the content of the line command
* @path : the current path
* Return :
*/
int create_child2(char **argv, char *path)
{
	int status = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	return (-1);
	if (pid == 0)
	execve(path, argv, NULL);
	else
	wait(&status);
	return (0);
}
#include "main.h"
/**
* check_stat - file status
* @argv : the file content
* Return : 0
*/
int check_stat(char *argv)
{
	struct stat st;

	if (stat(argv, (&st)) == 0)
	{
		return (1); /* si consigue el archivo */
	}
	else
	{
		printf("No such file or directory\n");
		return (0);
	}
}
