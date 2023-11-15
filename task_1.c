#include "main.h"
/**
 * cret_ver - this porgram creats a small version of the unix
 * system handling only executables
 *Return: void for success
 */
void cret_ver(void)
{
	char *lineptr = NULL, *token, *delim = " ", *args[100];
	size_t n = 0;
	char *ola_law = "ola_law$ ", *error = "No such file or directory\n";
	ssize_t getnum;
	pid_t proc;

	while (1)
	{
		write(STDOUT_FILENO, ola_law, strlen(ola_law));
		getnum = getline(&lineptr, &n, stdin);

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
	free(lineptr);
}
