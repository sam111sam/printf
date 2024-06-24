#include "main.h"
/**
 * _printf - mini printf
 * @format: format str
 * @...: variable args
 * Return: int
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;
	char *tmp;
	char a;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		switch (format[i])
		{
			case '%':
				if (format[i + 1] == 'c')
				{
					a = (char) va_arg(args, int);
					count += write(1, &a, 1);
					i++;
				}
				else if (format[i + 1] == '%')
				{
					a = '%';
					count += write(1, &a, 1);
					i++;
				}
				else if (format[i + 1] == 's')
				{
					tmp = va_arg(args, char *);
					count += write(1, tmp, strlen(tmp));
					i++;
				}
				else
				{
					a = '%';
					count += write(1, &a, 1);
				}
				break;


			default:
				count += write(1,&format[i], 1);
		}
		i++;
	}
	return (count);
}
