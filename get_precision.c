#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int c = *i + 1;
	int pr = -1;

	if (format[c] != '.')
		return (pr);

	pr = 0;

	for (c += 1; format[c] != '\0'; c++)
	{
		if (is_digit(format[c]))
		{
			pr *= 10;
			pr += format[] -'0';
		}
		else if (format[c] == '*')
		{
			c++;
			pr = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = c - 1;

	return (pr);
}
