#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

/**
 * main - function that exits the shell
 * a program implements a basic shell that
 * reads and executes user commands.
 * Return: 0 for success
 */

int main(void)
{
	char input[MAX_LINE_LENGTH];

	while (1)
	{
		printf("$ ");
		fflush(stdout);
	}

	if (fgets(input, MAX_LINE_LENGTH, stdin) == NULL)
	{
		perror("fgets");
		exit(1);
	}

	input[strcspn(input, "\n")] = '\0';

	if (strcmp(input, "exit") == 0)
	{
		printf("exiting shell.\n");
		break;
	}
	else
	{
		system(input);
	}
	return (0);
}
