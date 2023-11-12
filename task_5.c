#include "main.h"
/**
 * main - a function that prints the current environment
 * Return: 0 for success
 */

int main(void)
{
	char **env;
	pid_t proc;
	int status;

	printf("$ env\n");

	proc = fork();
	if (proc < 0)
		perror("fork error");
	else if (proc == 0)
	{
	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
		printf("$ exit\n");
	}
	else
	{
		proc = waitpid(proc, &status, 0);
		if (proc < 0)
		{
			dprintf(STDERR_FILENO, "parent process fail\n");
			exit(100);
		}
	}

	return (0);
}
