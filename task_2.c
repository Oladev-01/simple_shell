#include "main.h"
/**
 *main - this function creates a version of the unix env that
 * executes commands and accepts args
 *Return: 0 for success
 */
int main(void)
{
char *lineptr = NULL, *token, *args[100];
size_t n = 0;
char *ola_law = "ola_law$ ", *error = "no such file or directory\n";
int i = 0;

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
	  token = strtok(lineptr, " ");
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;
	pid_t proc = fork();

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
	free(lineptr);
	return (0);
}

/**
 * my_parent_id - this functon handles the parent process
 *@proc: this is the id of the passed from the child process
 *Return: void
 */
void my_parent_id(pid_t proc)
{
	char *error = "no such file or directory\n";
	int status;

	waitpid(proc, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 1)
		write(STDERR_FILENO, error, strlen(error));
	exit(100);
}
