#include "main.h"

/**
 * get_size - Calculates the size
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: size.
 */
int get_size(const char *format, int *i)
{
	int c = *i + 1;
	int s = 0;

	if (format[c] == 'l')
		s = S_LONG;
	else if (format[c] == 'h')
		s = S_SHORT;

	if (s == 0)
		*i = c - 1;
	else
		*i = c;

	return (s);
}
