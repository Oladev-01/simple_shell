#include "main.h"
/**
 * main - a function that reads user input and
 * checks if the command exists
 * Return:  for success 0
 */
int main(void) {
	char input[BUFF], *token;
	int argCount;
	char *args[32], *command, *path, *path_copy, *dir, cmd_path[BUFF];

	while (1)
	{
		printf("$ ola_law ");

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
		path = getenv("PATH");

		if (path != NULL)
		{
			path_copy = strdup(path);
			dir = strtok(path_copy, ":");
		}

		while (dir != NULL)
		{
			snprintf(cmd_path, sizeof(cmd_path), "%s/%s", dir, command);

			if (access(cmd_path, X_OK) == 0)
			{
				execvp(cmd_path, args);
				perror("Error executing command");
				break;
			}

			dir = strtok(NULL, ":");
		}

		if (dir == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", command);
		}

		free(path_copy);
	}

	return (0);
}
