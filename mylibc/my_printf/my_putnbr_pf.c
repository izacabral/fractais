
#include "my_printf.h"

int	my_putnbr_pf(int n)
{
	long int	nbr;
	int			length;

	length = 0;
	nbr = n;
	if (nbr < 0)
	{
		length += my_putchar_pf('-');
		nbr = nbr * -1;
	}
	if (nbr > 9)
		length += my_putnbr_pf(nbr / 10);
	length += my_putchar_pf((nbr % 10) + '0');
	return (length);
}
