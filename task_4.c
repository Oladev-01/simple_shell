#include "main.h"
/**
 * exit_shell - function that exits the shell
 * a program implements a basic shell that
 * reads and executes user commands.
 * Return: 0 for success
 */

void exit_shell(void)
{
	char input[BUFF];

	while (1)
	{
		printf("$ ola_law ");
	if (fgets(input, BUFF, stdin) == NULL)
	{
		perror("fgets");
		exit(100);
	}

	input[strcspn(input, "\n")] = '\0';

	if (strcmp(input, "exit") == 0)
	{
		printf("exiting shell.\n");
		exit(0);
	}
	else
	{
		system(input);
	}
	}
}
