#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @s: Char to be evaluated.
 * Return: 1 if c is printable.
 */
int is_printable(char s)
{
	if (s >= 32 && s < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buf: Array of chars.
 * @i: Index to start appending.
 * @asci_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char asci_code, char buf[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (asci_code < 0)
		asci_code *= -1;

	buf[i++] = '\\';
	buf[i++] = 'x';

	buf[i++] = map_to[asci_code / 16];
	buf[i] = map_to[asci_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @s: evaluat char
 * Return: 1 if c is a digit
 */
int is_digit(char s)
{
	if (s >= '0' && s <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @number: Number to be casted.
 * @size: Number indicating the type to be casted.
 * Return: Casted value of num
 */
long int convert_size_number(long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((short)number);

	return ((int)number);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @number: casted number
 * @size: Number indicating the type to be caste
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int number, int size)
{
	if (size == S_LONG)
		return (number);
	else if (size == S_SHORT)
		return ((unsigned short)number);

	return ((unsigned int)number);
}

