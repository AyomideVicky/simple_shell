#include "shell.h"

/**
 * prompt - dispplay the prompt symbil $
 * @fd: File Descriptor
 * @buf: Status Structure
 * Return: void
 */

void prompt(int fd, struct stat buf)
{
	fstat(fd, &buf);
	if (S_ISCHR(buf.st_mode))
	{
		_puts("$ ");
	}
}

/**
  * _puts - prints string without newline
  * @str: string to print
  * Return: void
  */

void _puts(char *str)
{
	unsigned int length;

	length = strlen(str);
	write(STDOUT_FILENO, str, length);
}
