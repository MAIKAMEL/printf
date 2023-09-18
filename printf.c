#include "main.h"

/**
 * _printf -  print anything
 * @format: this is a string
 * Return: number of bytes printed
 *
*/

int _printf(const char *format, ...)
{
	int count = 0;
	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
		}
		format++;
	}
	return (count);
}
