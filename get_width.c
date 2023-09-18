#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: string to print the arguments
 * @li: List of arguments
 * @list: list of arguments.
 * Return: width.
 */
int get_width(const char *format, int *li, va_list list)
{
	int current_li;
	int width = 0;

	for (current_li = *li + 1; format[current_li] != '\0'; current_li++)
	{
		if (is_digit(format[current_li]))
		{
			width *= 10;
			width += format[current_li] - '0';
		}
		else if (format[current_li] == '*')
		{
			current_li++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*li = current_li - 1;

	return (width);
}

