#include "main.h"
/**
 * _printf - mini printf
 * @format: format str
 * @...: variable args
 * Return: int
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0, r_count;
	va_list args;
	va_list args_copy;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	va_copy(args_copy, args);

	while (format[i])
	{
		switch (format[i])
		{
			case '%':
				r_count = check(args_copy, (format + i + 1));
				if (r_count  > 0)
				{
					count += r_count;
					i++;
				}
				else
				{
					return (-1);
				}
				break;
			default:
				count += write(1, &format[i], 1);
		}
		i++;
	}
	return (count);
}
/**
 * check - check the str specifier
 * @args: args
 * @cp: char pointer
 * Return: int
 */
int check(va_list args, const char *cp)
{
	char *tmp, a;

	if (*cp == 'c')
	{
		a = (char) va_arg(args, int);
		return (write(1, &a, 1));
	}
	else if (*cp == '%')
	{
		a = '%';
		return (write(1, &a, 1));
	}
	else if (*cp == 's')
	{
		tmp = va_arg(args, char *);
		if (tmp)
			return (write(1, tmp, strlen(tmp)));
		else
			return (write(1, "(null)", 6));
	}
	else
	{
		tmp = "Error";
		write(2, &a, strlen(tmp));
		return (-1);
	}
}



