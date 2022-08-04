#include "main.h"
/**
 * main - main function
 * @ac: saves the memory adress
 * @av: pointer to pointer
 * Return: 0
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

int check_dir(char *array)
{
    int i = 0;

    for (i = 0; array[i]; i++)
    {
        if (array[i] == '/')
            return(1);
    }
	return (0);
}
char *check_path(char *buffer, char **array_path)
{
    struct stat st;
    int i = 0;
    char *dir = NULL;

    for (i = 0; array_path[i]; i++)
    {                                                                                                    
		dir = malloc(strlen(buffer) + strlen(array_path[i]) + 1000);
		if (dir == NULL)
			return(NULL);
		strcpy(dir, array_path[i]);
		strcat(dir, "/");
		strcat(dir, buffer);
		if (stat(dir, &st) == 0)
		{
			printf("%s: te encontre\n", dir);
			return(dir);
		}
		else
            free(dir);
	}
    printf("command no found\n");
    return (NULL);
}

int main(void)
{
	int status = 0;
	char *buffer = NULL, *path = NULL;
	char *array[1020], *array_dir[1020];
	size_t size = 0, prompt = 0, ctrl_d = -1;
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
            return(copy);
        }
    }
    return (NULL);
}

void get_path(char **array_dir)
{
    int i = 0;
    char *copy = strdup(_getenv("PATH="));
    char *dir = NULL;

    if (array_dir)
    {
        strtok(copy, ":=");
        dir = strtok(NULL, ":=");
        for (i = 0; dir[i]; i++)
        {
            dir = strtok(NULL, ":=");
            array_dir[i] = strdup(dir);
        }
        array_dir[i] = NULL;
        free(copy);
    }
}

	while (EOF)
	{
		get_path(array_dir);
		if (isatty(0))
			printf("#cisfun$ ");
		/* espero que el usuario pase algo */
		do { /* ejecuta y luego condiciona */
			prompt = getline(&buffer, &size, stdin);
			if (prompt == ctrl_d) /* ctrl + d */
			{
				/* libero memoria si falla, buffer es el malloc interno de getline*/
				free_array_dir(array_dir);
				free(buffer);
				exit(0);
			}
		} while (buffer[0] == '\n' && prompt > ctrl_d);
		if (check_space(buffer))
		{
			tokenizer(buffer, array, "\t\n ");
			if (check_dir(array[0]))
			{
				status = check_stat(array[0]);
				if (status)
					create_child(array);
			}
			else
			{
				path = check_path(array[0], array_dir);
				execve(path, array, NULL);
			}
		}
		free_array_dir(array_dir);
	}
	return (0);
}

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
		if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\t')
			return (1);
	}
	return (0);
}
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
            return(copy);
        }
    }
    return (NULL);
}

void get_path(char **array_dir)
{
    int i = 0;
    char *copy = strdup(_getenv("PATH="));
    char *dir = NULL;

    if (array_dir)
    {
        strtok(copy, ":=");
        dir = strtok(NULL, ":=");
        for (i = 0; dir[i]; i++)
        {
            dir = strtok(NULL, ":=");
            array_dir[i] = strdup(dir);
        }
        array_dir[i] = NULL;
        free(copy);
    }
}

