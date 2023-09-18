/* print_int - Print an integer
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int negative = 0;
	long int h = va_arg(types, long int);
	unsigned long int num;

	h = convert_size_number(h, size);

	if (h == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)h;

	if (h < 0)
	{
		num = (unsigned long int)((-1) * h);
		negative = 1;
	}

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;

	return (write_number(negative, x, buffer, flags, width, precision, size));
}

