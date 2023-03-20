
#include "my_printf.h"

int	my_puthexx_pf(unsigned int n)
{
	unsigned int	i;
	int				length;
	char			*x;

	i = 0;
	x = "0123456789ABCDEF";
	length = 0;
	if (n > 15)
		length += my_puthexx_pf(n / 16);
	i = n % 16;
	length += my_putchar_pf(x[i]);
	return (length);
}
