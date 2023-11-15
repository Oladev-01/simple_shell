#include "main.h"
/**
 * main - function that exits the shell
 * a program implements a basic shell that
 * reads and executes user commands.
 * Return: 0 for success
 */

int main(void)
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
		break;
	}
	else
	{
		system(input);
	}
	}
	return (0);
}
