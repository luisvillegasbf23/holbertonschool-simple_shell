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
	char *argv[] = {"", NULL};
	size_t size = 0, prompt = 0, ctrl_d = -1;

	while (1)
	{
		printf("#cisfun$ ");
		/* espero que el usuario pase algo */
		prompt = getline(&buffer, &size, stdin);
		strtok(buffer, "\n");
		argv[0] = buffer;
		if (prompt == ctrl_d) /* ctrl + d */
		{
			printf("\n");
			/* libero memoria si falla, buffer es el malloc interno de getline*/
			free(buffer);
			break;
		}
		status = check_stat(argv[0], av[0]);
		if (status)
			create_child(argv);
	}
	return (0);
}

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
