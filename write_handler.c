#include "main.h"

/*WRITE HANDLE*/
/**
 * handle_write_char - Prints a string
 * @s: char types.
 * @buf: Buffer array to handle print
 * @flag:  Calculates active flags.
 * @width: get width.
 * @preci: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char s, char buf[], int flag,
	int width, int preci, int size)
{
	int i = 0;
	char padding = ' ';

	UNUSED(preci);
	UNUSED(size);

	if (flag & F_ZERO)
		padding = '0';

	buf[i++] = s;
	buf[i] = '\0';

	if (width > 1)
	{
		buf[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buf[BUFF_SIZE - i - 2] = padding;

		if (flag & F_MINUS)
			return (write(1, &buf[0], 1) +
					write(1, &buf[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buf[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buf[0], 1));
	}

	return (write(1, &buf[0], 1));
}

/*WRITE NUMBER*/
/**
 * write_number - Prints a string
 * @is_neg: Lista of arguments
 * @ind: char types.
 * @buf: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @preci: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_neg, int ind, char buf[],
	int flag, int width, int preci, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padding = ' ', extra_char = 0;

	UNUSED(size);

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padding = '0';
	if (is_neg)
		extra_char = '-';
	else if (flag & F_PLUS)
		extra_char = '+';
	else if (flag & F_SPACE)
		extra_char = ' ';

	return (write_num(ind, buf, flag, width, preci,
		length, padding, extra_char));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buf: Buffer
 * @flag: Flags
 * @width: width
 * @preci: Precision specifier
 * @length: Number length
 * @padding: Pading char
 * @extra_char: Extra char
 *
 * Return: Number of printed chars.
 */
int write_num(int ind, char buf[], int flag, int width,
	int preci, int length, char padding, char extra_char)
{
	int i, padding_start = 1;

	if (preci == 0 && ind == BUFF_SIZE - 2 && buf[ind] == '0' && width == 0)
		return (0);
	if (preci == 0 && ind == BUFF_SIZE - 2 && buf[ind] == '0')
		buf[ind] = padding = ' ';
	if (preci > 0 && preci < length)
		padding = ' ';
	while (preci > length)
		buf[--ind] = '0', length++;
	if (extra_char != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buf[i] = padding;
		buf[i] = '\0';
		if (flag & F_MINUS && padding == ' ')
		{
			if (extra_char)
				buf[--ind] = extra_char;
			return (write(1, &buf[ind], length) + write(1, &buf[1], i - 1));
		}
		else if (!(flag & F_MINUS) && padding == ' ')
		{
			if (extra_char)
				buf[--ind] = extra_char;
			return (write(1, &buf[1], i - 1) + write(1, &buf[ind], length));
		}
		else if (!(flag & F_MINUS) && padding == '0')
		{
			if (extra_char)
				buf[--padding_start] = extra_char;
			return (write(1, &buf[padding_start], i - padding_start) +
				write(1, &buf[ind], length - (1 - padding_start)));
		}
	}
	if (extra_char)
		buf[--ind] = extra_char;
	return (write(1, &buf[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_neg: indicate if the num is negative
 * @ind: Index of the number starts in the buffer
 * @buf: Array of chars
 * @flag: specifiers of Flags
 * @width: specifiers of Width
 * @preci: specifiers of Precision
 * @size: specifiers of Size
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_neg, int ind, char buf[], int flag,
	int width, int preci, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padding = ' ';

	UNUSED(is_neg);
	UNUSED(size);

	if (preci == 0 && ind == BUFF_SIZE - 2 && buf[ind] == '0')
		return (0);

	if (preci > 0 && preci < length)
		padding = ' ';

	while (preci > length)
	{
		buf[--ind] = '0';
		length++;
	}

	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padding = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buf[i] = padding;

		buf[i] = '\0';

		if (flag & F_MINUS)
		{
			return (write(1, &buf[ind], length) + write(1, &buf[0], i));
		}
		else
		{
			return (write(1, &buf[0], i) + write(1, &buf[ind], length));
		}
	}

	return (write(1, &buf[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @buf: Arrays of chars
 * @ind: Index for the number starts in the buffer
 * @length: number Length
 * @width: specifier of Width
 * @flag: specifier of Flag
 * @padding: Char representing the padding
 * @extra_char: Char representing extra char
 * @padding_start: Index for  padding should start
 *
 * Return: Number of written chars.
 */
int write_pointer(char buf[], int ind, int length, int width,
	int flag, char padding, char extra_char, int padding_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buf[i] = padding;
		buf[i] = '\0';
		if (flag & F_MINUS && padding == ' ')
		{
			buf[--ind] = 'x';
			buf[--ind] = '0';
			if (extra_char)
				buf[--ind] = extra_char;
			return (write(1, &buf[ind], length) + write(1, &buf[3], i - 3));
		}
		else if (!(flag & F_MINUS) && padding == ' ')
		{
			buf[--ind] = 'x';
			buf[--ind] = '0';
			if (extra_char)
				buf[--ind] = extra_char;
			return (write(1, &buf[3], i - 3) + write(1, &buf[ind], length));
		}
		else if (!(flag & F_MINUS) && padding == '0')
		{
			if (extra_char)
				buf[--padding_start] = extra_char;
			buf[1] = '0';
			buf[2] = 'x';
			return (write(1, &buf[padding_start], i - padding_start) +
				write(1, &buf[ind], length - (1 - padding_start) - 2));
		}
	}
	buf[--ind] = 'x';
	buf[--ind] = '0';
	if (extra_char)
		buf[--ind] = extra_char;
	return (write(1, &buf[ind], BUFF_SIZE - ind - 1));
}

