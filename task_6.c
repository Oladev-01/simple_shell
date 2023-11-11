#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * main - program main function
 * Return: always 0 for success
 */

int main(void)
{
	char *line;

	while (1)
	{
		printf("shell> ");
		line = custom_getline();
	}
	if (!line)
	{
		printf("Exiting shell.\n");
		break;
	}
	printf("Enter: %s\n", line);
	free(line);

	return (0);
}

/**
 * custom_getline - read a line of input from the user
 *
 * Return: allocated string containing the entered line
 * Null if the end of line is reached or an error occurs
 */

int custom_getline(void)
{
	int i = 0;
	static char buf[BUFFER_SIZE];
	static size_t buf_ind;
	static ssize_t bytes_rd;

	if (buf_ind >= bytes_rd || bytes_rd == 0)
	{
		bytes_rd = rd(STDIN_FILENO, buf, BUFFER_SIZE);
	}

	if (bytes_rd <= 0)
	{
		return (NULL);
	}
	buf_ind = 0;
	start_ind = buf_ind;

	while (buf_ind < bytes_rd && buf[buf_ind] != '\n')
	{
		buf_ind++;
	}

	line_length = buf_ind - start_ind;
	line = malloc(line_length + 1);

	if (!line)
	{
		perror("malloc");
		exit(exit_failure);
	}

	for (i = 0; i < line_length; i++)
	{
		line[i] = buf[start_ind + i];
	}

	line[line_length] = '\0';

	if (buf_ind < bytes_rd && buf[buf_ind] == '\n')
	{
		buf_ind++;
	}
	return (line);
}
