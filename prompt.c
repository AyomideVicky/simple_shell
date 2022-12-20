#include "shell.h"

/**
 * prompt -
 * @fd: File Descriptor
 * @buf: Status Structure
 * Return: void
 */

void prompt (int fd, struct stat buf)
{
	fstat(fd, &buf);
	if (S_ISCHR(buf.st_mode))
	{
		_puts("$ ");
	}
}

void _puts(char *str)
{
	unsigned length;
	length = strlen(str);
	write(STDOUT_FILENO, str, length);
}
