#include "main.h"
/**
* main - main function
* Return: 0
*/
int main(void)
{
	char *buffer = NULL, *path = NULL;
	char *array[1020], *array_dir[1024];
	size_t size = 0, prompt = 0, ctrl_d = -1;

	while (EOF)
	{
		if (isatty(0))
			printf("#cisfun$ ");
		do { /* ejecuta y luego condiciona */
			prompt = getline(&buffer, &size, stdin);
			if (prompt == ctrl_d) /* ctrl + d */
			{/* libero memoria si falla, buffer es el malloc interno de getline*/
				free(buffer);
				exit(0);
			}
		} while (buffer[0] == '\n' && prompt > ctrl_d);
		if (check_space(buffer))
		{
			tokenizer(buffer, array, "\t\n ");
			if (check_dir(array[0]))
			{
				if (check_stat(array[0]))
					create_child(array);
			}
			else
			{
				path = check_path(array[0], array_dir);
				if (path)
				{
					create_child2(array, path);
					free(path);
					free_array_dir(array_dir);
				}
				else
					printf("command no found\n");
			}
		}
	}
	return (0);
}
