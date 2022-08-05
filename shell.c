#include "main.h"
/**
* main - main function
* Return: 0
*/
int main(void)
{
	int status = 0;
	char *buffer = NULL, *path = NULL;
	char *array[1020], *array_dir[1020];
	size_t size = 0, prompt = 0, ctrl_d = -1;

	while (EOF)
	{
		if (isatty(0))
			printf("#cisfun$ ");
		get_path(array_dir);
		/* espero que el usuario pase algo */
		do { /* ejecuta y luego condiciona */
			prompt = getline(&buffer, &size, stdin);
			if (prompt == ctrl_d) /* ctrl + d */
			{/* libero memoria si falla, buffer es el malloc interno de getline*/
				free(buffer);
				free_array_dir(array_dir);
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
				if (path != NULL)
				{
					create_child2(array, path);
					free(path);
				}
				else
					printf("command no found\n");
			}
		}
		free_array_dir(array_dir);
	}
	return (0);
}
