#include <stdio.h>
#include <stdlib.h>

/**
 * main - a function that prints the current environment
 * Return: 0 for success
 */

int main(void)
{
	for (char **env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}

	return (0);
}
