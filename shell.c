#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main ()
{
	char *buffer = NULL;
	size_t bufsize = 0;
	int status, pid;
	char *argv[] = {"", NULL};
	char *tok; 
	struct stat st;
	
	while (1)
	{
		printf("#cisfun$ ");
		getline(&buffer, &bufsize, stdin);
		tok = strtok(buffer, "\n");
		buffer = tok;
		argv[0] = buffer;
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			if (stat(argv[0],&st) == 0)
			{
				printf("%s", buffer);
				execve(argv[0], argv, NULL);
			}
			else
				printf("file %s not found\n", argv[0]);
		}
		else
			wait(&status);
	}
	free(buffer);
	return (0);
}
