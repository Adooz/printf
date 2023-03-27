#include "main.h"
#include <unistd.h>

/**
 * __prints - writes a string to stdout
 * @str: the string to write
 * @size: the number of bytes to write
 *
 * Return: void
 */

void __prints(char *str, int size)
{
	write(1, str, size);
}
