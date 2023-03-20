
#include "my_printf.h"

static int	my_puthex(unsigned long int n)
{
	unsigned long int	i;
	int					length;
	char				*x;

	i = 0;
	x = "0123456789abcdef";
	length = 0;
	if (n > 15)
		length += my_puthex(n / 16);
	i = n % 16;
	length += my_putchar_pf(x[i]);
	return (length);
}

int	my_puthexp_pf(unsigned long int nbr)
{
	int	length;

	length = 0;
	length += write (1, "0x", 2);
	length += my_puthex(nbr);
	return (length);
}
