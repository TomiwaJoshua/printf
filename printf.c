#include "main.h"

/**
 * _printf - my printf function
 * @format: string with formats for printing
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list list;
	int length = 0;

	if (!format)
		return (-1);

	va_start(list, format);

	length = _printformat(format, list);
	va_end(list);

	return (length);
}
