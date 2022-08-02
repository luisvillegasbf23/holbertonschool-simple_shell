#include "main.h"
/**
 * main - main function
 * @ac: saves the memory adress
 * @av: pointer to pointer
 * Return: 0
 */
int main(__attribute__((unused))int ac, char **av)
{
	int status = 0;
	char *buffer = NULL;
	char *array[1020];
	size_t size = 0, prompt = 0, ctrl_d = -1;

	while (EOF)
	{
		if (isatty(0))
			printf("#cisfun$ ");
		/* espero que el usuario pase algo */
		do { /* ejecuta y luego condiciona */
			prompt = getline(&buffer, &size, stdin);
		} while (buffer[0] == '\n' && prompt > 1);
		if (prompt == ctrl_d) /* ctrl + d */
		{
			/* libero memoria si falla, buffer es el malloc interno de getline*/
			free(buffer);
			break;
		}
		if (check_space(buffer))
		{
			tokenizer(buffer, array, "\n ");
			status = check_stat(array[0], av[0]);
			if (status)
				create_child(array);
		}
	}
	return (0);
}

/**
* check_stat - checks the status of father process
* @argv : 
* @av : 
* Return : 
*/
int check_stat(char *argv, char *av)
{
	struct stat st;

	if (stat(argv, (&st)) == 0)
	{
		return (1); /* si consigue el archivo */
	}
	else
	{
		printf("%s: No such file or directory\n", av);
		return (0);
	}
}

/**
* create_child - 
* @argv : pointer to pointer
* Return : 
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

/**
* tokenizer - 
* @buffer : 
* @array : pointer of pointer
* @delim :
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

/**
* check_space - 
* @buffer : 
*/
int check_space(char *buffer)
{
	int i = 0;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] != ' ' && buffer[i] != '\n')
			return (1);
	}
	return (0);
}


/* acomodar modo no interactivo */
