#include "main.h"
/**
 * main - this porgram creats a small version of the unix
 * system handling only executables
 *Return: 0 for success
 */
int main(void)
{
	char *lineptr = NULL, *token, *delim = " ", *args[100];
	char *path = "/usr/bin/ls";
	size_t n = 0;
	char *ola_law = "ola_law$ ", *error = "No such file or directory\n";
	int status, a = 0, b = 0;

	while (1)
	{
		write(STDOUT_FILENO, ola_law, strlen(ola_law));
		ssize_t getnum = getline(&lineptr, &n, stdin);

		if (getnum == -1)
		{
			write(STDERR_FILENO, error, strlen(error));
			break;
		}
		if (lineptr[getnum - 1] == '\n')
			lineptr[getnum - 1] = '\0';
		token = strtok(lineptr, delim);
		args[0] = token;
		args[1] = NULL;
		pid_t proc = fork();

		if (proc == -1)
			perror("child process fail");
		else if (proc == 0)
		{
			if (execvp(args[0], args) == -1)
				exit(99);
		}
		else
		{
			waitpid(proc, &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
				write(STDERR_FILENO, error, strlen(error));
			exit(100);
		}
	}
	free(lineptr);
	return (0);
}
