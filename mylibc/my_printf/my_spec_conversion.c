
#include "my_printf.h"

int	my_spec_conversion(const char *fmt, int i, va_list args)
{
	if (fmt[i + 1] == 'c')
		return (my_putchar_pf(va_arg(args, int)));
	else if (fmt[i + 1] == 's')
		return (my_putstr_pf(va_arg(args, char *)));
	else if (fmt[i + 1] == 'p')
		return (my_puthexp_pf(va_arg(args, unsigned long int)));
	else if (fmt[i + 1] == 'd' || fmt[i + 1] == 'i')
		return (my_putnbr_pf(va_arg(args, int)));
	else if (fmt[i + 1] == 'u')
		return (my_putnbru_pf(va_arg(args, unsigned int)));
	else if (fmt[i + 1] == 'x')
		return (my_puthex_pf(va_arg(args, unsigned int)));
	else if (fmt[i + 1] == 'X')
		return (my_puthexx_pf(va_arg(args, unsigned int)));
	else if (fmt[i + 1] == '%')
		return (my_putchar_pf(fmt[i + 1]));
	return (0);
}
