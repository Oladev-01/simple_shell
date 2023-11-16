#include <stdio.h>
#include <unistd.h>

/**
 * execute_command - Executes a command
 * @command: The command to be executed
 * Returns: An integer representing the execution status
 */
int execute_command(const char *command)
{
	const char *cmd_path = command;
	char *args[] = {command, NULL};

	if (access(cmd_path, X_OK) == 0)
	{
		execvp(cmd_path, args);
		perror("Error executing command");
		return (-1);
	}

	return (0);
}

/**
 * search_execute_command - a function that search, execute a command
 * Search for the command in PATH directories and execute if found.
 * @cmd_path: path to the command executable
 * @args: array of arguments for the command
 * Returns: An integer indicating the search and execution status
 */

int search_execute_command(const char *command, char *const args[])
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");
	char cmd_path[BUFF];

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found\n");
		return (-1);
	}

	if (path_copy == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		return (-1);
	}

	while (dir != NULL)
	{
		snprintf(cmd_path, sizeof(cmd_path), "%s/%s", dir, command);
	}

	if (execute_command(cmd_path, args) == 0)
	{
		free(path_copy);
		return (0);
	}

	dir = strtok(NULL, ":");

	fprintf(stderr, "Command not found: %s\n", command);
	free(path_copy);
	return (-1);
}

/**
 * read_input - function that reads input
 * Reads user input, tokenizes it, and executes the command.
 * Returns: a string containing the user input
 */
int read_input(void)
{
	char input[BUFF], *token;
	int argCount;
	char *args[32], *command;

	while (1)
	{
		printf("$ ola_law ");
	}

	if (fgets(input, sizeof(input), stdin) == NULL)
	{
		break;
	}

	input[strcspn(input, "\n")] = '\0';
	argCount = 0;

	token = strtok(input, " ");

	while (token != NULL && argCount < 31)
	{
		args[argCount++] = token;
		token = strtok(NULL, " ");
	}

	if (argCount == 0)
	{
		fprintf(stderr, "Error: No command specified\n");
		continue;
	}

	args[argCount] = NULL;
	command = args[0];

	if (search_execute_command(command, args) == -1)
	{
		return (-1);
	}

	return (0);
}
