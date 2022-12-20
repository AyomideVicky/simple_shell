#include "shell.h"

/**
 * main - Entry Point
 * @argc: argument count
 * @argv: Argument Vector
 * Return - always 0
 */


int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	char *line, *path, *fullpath;
	char **token;
	int flag, child_status, builtin_status;
	struct stat buf;

	while (1)
	{
		prompt(STDOUT_FILENO, buf);
		line = _getline(stdin);
		printf("%s", line);
		if (strcmp(line, "\n") == 0)
		{
			free(line);
			continue;
		}
		token = tokenizer(line);
		if (token[0] == NULL)
			continue;
		builtin_status = builtin_execute(tokens);
		if (builtin_status == 0 || builtin_status == -1)
		{
			free(tokens);
			free(line);
		}
		if (builtin_status == 0)
			continue;
		if (builtin_status == -1)
			_exit(EXIT_SUCCESS);
		flag = 0; /* 0 if full_path is not malloc'd */
		path = _getenv("PATH");
		fullpath = _which(tokens[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tokens[0];
		else
			flag = 1; /* if fullpath was malloc'd, flag to free */
		child_status = child(fullpath, tokens);
		if (child_status == -1)
			errors(2);
		free_all(tokens, path, line, fullpath, flag);
	}
	return (0);
}
