#include "main.h"
#include <stdarg.h>
/**
 * _printf - prints output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, len;
	char *s;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				__prints(&c, 1);
				count += 1;
			}
			if (format[i] == 's')
			{
				s = va_arg(args, char *);

				if (s)
				{
					len = 0;

					while (s[len])
						len++;

					__prints(s, len);
					__prints('\0', 1);
					count += len;
				}
				else
				{
					s = "(null)";
				}
			}
			if (format[i] == '%')
			{
				__prints("%", 1);
				count += 1;
			}
			else
			{
				__prints("%", 1);
				__prints((char *)&format[i], 1);
				count += 2;
			}
		}
		else
		{
			__prints((char *)&format[i], 1);
			count += 1;
		}
		i++;
	}
	va_end(args);
	return (count);
}
