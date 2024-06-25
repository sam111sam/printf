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

				if (r_count >= 0)
					count += r_count;
				else
					return (r_count);

				if (format[i + 1] == 'c' || format[i + 1] == '%' || format[i + 1] == 's')
					i++;
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
	int x;

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
	else if (*cp == 'd' || *cp == 'i')
	{
		x =  va_arg(args, int);
		return (write(1, &x, sizeof(x)));
	}
	else
	{
		tmp = "";
		if (*cp != 0 && *cp != ' ')
			tmp = "%";
		else
			return (-1);
		return (write(1, tmp, strlen(tmp)));
	}
}



