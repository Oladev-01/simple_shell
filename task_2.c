#include "main.h"
/**
 *cret_ver_2 - this function creates a version of the unix env that
 * executes commands and accepts args
 *@lineptr: this is the string that should contain the command
 *Return: 0 for success
 */
void cret_ver_2(char *lineptr)
{
char *token, *args[100];
int i = 0;
pid_t proc;

	  token = strtok(lineptr, " ");
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	proc = fork();

	if (proc == -1)
		perror("child process fail");
	else if (proc == 0)
	{
	if (execvp(args[0], args) == -1)
		exit(99);
	}
	else
		my_parent_id(proc);
}

/**
 * my_parent_id - this functon handles the parent process
 *@proc: this is the id of the passed from the child process
 *Return: void
 */
void my_parent_id(pid_t proc)
{
	int status;

	waitpid(proc, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
	{
		perror("Parent process fail");
		exit(100);
	}
}
