
#include "my_printf.h"

int	my_putchar_pf(char c)
{
	int	len;

	len = 0;
	len += write (1, &c, 1);
	return (len);
}
