
#include "my_printf.h"

int	my_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			ret += my_putchar_pf(format[i]);
		if (format[i] == '%' && my_strchr("cspdiuxX%", format[i + 1]))
		{
			ret += my_spec_conversion(format, i, args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (ret);
}	
