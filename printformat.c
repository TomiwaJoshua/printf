#include "main.h"

/**
 * _printformat - prints the format
 * @s: input string
 * @args: variable argument list
 * Return: returns the length of the format
 */
int _printformat(const char *s, va_list args)
{
	int i = 0, count = 0;

	while (s && s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
				return (-1);
			i++;
			if (s[i] == '%')
				count += _putchar(s[i]);
			if (s[i] != '%' && _check(s[i]) == 0)
			{
				count = _wrongformat(s[i], count);
			}
			else if (s[i] != '%' && _check(s[i]) == 1)
			{
				count += _printspec(s[i], args);
			}
		}
		else
		{
			count += _putchar(s[i]);
		}
		i++;
	}
	return (count);
}

/**
 * _check - checks for a format specifier
 * @a: character to check
 * Return: returns 0 if format specifier is found and 1 if otherwise
 */
int _check(char a)
{
	char formats[7] = "csidb";
	int i = 0;

	while (formats[i] != '\0')
	{
		if (formats[i] == a)
			return (1);
		i++;
	}
	return (0);
}
/**
 * _wrongformat - prints an invalid specifier
 * @format: character input
 * @count: current string count prior to invalid format
 * Return: returns the correct count after printing the invalid specifiers
 */
int _wrongformat(char format, int count)
{
	count += _putchar('%');
	count += _putchar(format);

	return (count);
}
/**
 * _printspec - prints a valid specifier
 * @format: format specifier
 * @args: variable arguments
 * Return: returns the length of the specifier
 */
int _printspec(char format, va_list args)
{
	int i = 0, length = 0;
	spc_dt _types[] = {
		{"c", _print_a_char},
		{"s", _print_a_string},
		{"d", _print_a_integer},
		{"i", _print_a_integer},
		{"b", _print_int_binary},
		{NULL, NULL}
	};

	while (_types[i].specifier)
	{
		if (*_types[i].specifier == format)
			length = _types[i].f(args);

		i++;
	}

	return (length);
}
