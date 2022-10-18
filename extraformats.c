#include "main.h"

/**
 * base_converter - converts an integer to a string in a certain base
 * @x: integer input
 * @base: base input
 * Return: returns the count
 */

int base_converter(int x, int base)
{
	int y, b, count = 0;
	int alloc = 1;
	char *str;

	str = malloc(alloc);
	if (x == 0)
	{
		_putchar(0 + '0');
		return (1);
	}

	if (x < 0)
	{
		x = x * -1;
	}

	while (x > 0)
	{
		y = x % base;
		str[count] = y + '0';
		str = realloc(str, ++alloc);
		count++;
		x = (x / base);
	}
	str[count] = '\0';

	b = count;

	while (b >= 0)
	{
		_putchar(str[b]);
		b--;
	}

	free(str);

	return (count);
}

/**
 * _print_int_binary - Prints a int converted to binary
 * @args: A list of variadic arguments
 *
 * Return: the number of printed digites
 */

int _print_int_binary(va_list args)
{
	int count;

	count = base_converter(va_arg(args, int), 2);
	return (count);
}
