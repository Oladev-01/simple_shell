#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

/**
 * main - a function that reads user input and
 * checks if the command exists
 * Return:  for success 0
 */

int main(void)
{
	char input[MAX_INPUT_SIZE];
	int argCount = 0;
	char *token = strtok(input, " ");
	char *args[32], *command, *path, *path_copy, *dir, cmd_path[1024];

	while (1)
	{
		printf("$ ");
		fflush(stdout);
	}
	if ((fgets(input, sizeof(input), stdin)) == NULL)
	{
		break;
	}

	input[strcspn(input, "\n")] = '\0';

	token = strtok(input, " ");
	while (token != NULL)
	{
		args[argCount] = token;
		argCount++;
	}

	if (argCount == 32)
	{
		fprintf(stderr, "Error: Too many arguments");
		break;
	}

	token = strtok(NULL, " ");
	args[argCount] = NULL;

	if (argCount = 0)
	{
		command = args[0];
		path = getenv("PATH");
	}
	if (path != NULL)
	{
		path_copy = strdup(path);
		dir = strtok(path_copy, ": ");
	}
	while (dir != NULL)
	{
		cmd_path [1024];
		snprintf(cmd_path, sizeof(cmd_path), "%s/%s", dir, command);
	}

	if (access(cmd_path, X_OK) == 0)
	{
		execvp(cmd_path, args);
		perror("Error executing command");
		break;
	}
	
	dir = strtok(NULL, ": ");
	free(path_copy);
	fprintf(stderr, "Command not found %s\n", command);

	return (0);
}
		
