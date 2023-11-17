#include "main.h"
/**
 * exit_shell - function that exits the shell
 * a program implements a basic shell that
 * reads and executes user commands.
 *@input: this is the string that should contain the exit command
 * Return: 0 for success
 */

void exit_shell(char *input)
{
	input[strcspn(input, "\n")] = '\0';

	if (strcmp(input, "exit") == 0)
	{
		exit(0);
	}
	else
	{
		system(input);
	}
}
