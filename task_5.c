#include "main.h"
/**
 * print_env - a function that prints the current environment
 * Return: 0 for success
 */

void print_env(void)
{
	char **env;
	pid_t proc;
	int status;

	proc = fork();
	if (proc < 0)
		perror("fork error");
	else if (proc == 0)
	{
	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
	exit(0);
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
}
