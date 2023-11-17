#include "main.h"
/**
 * simple_shell - this is the bare bone version of the UNIX
 * Return: void
 */
void simple_shell(void)
{
	char *getstr, exit_out[10] = "exit", envi[10] = "env", *envr[10];
	ssize_t num;
	size_t n = 0;
	int i;

	while (1)
	{
		num = getline(&getstr, &n, stdin);
		if (num < 0)
		{
			dprintf(STDERR_FILENO, "No such file or directory\n");
			break;
		}
		if (getstr[num - 1] == '\n')
			getstr[num - 1] = '\0';
		for (i = 0; getstr[i] != '\0'; i++)

		if (strcmp(getstr, exit_out) == 0)
			exit_shell(getstr);
		if (strcmp(getstr, envi) == 0)
		{
			*envr[10] = *getstr;
			print_env(envr);
		}
		else
			cret_ver_2(getstr);

	}
}
