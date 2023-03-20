
#include "my_printf.h"

int	my_putnbru_pf(unsigned int n)
{
	long int	nbr;
	int			length;

	length = 0;
	nbr = n;
	if (nbr > 9)
		length += my_putnbru_pf(nbr / 10);
	length += my_putchar_pf((nbr % 10) + '0');
	return (length);
}
