
#include "my_printf.h"

int	my_putstr_pf(char *s)
{
	int	length;

	length = 0;
	if (!s)
	{
		length += write(1, "(null)", 6);
		return (length);
	}
	while (*s)
	{
		length += write (1, s++, 1);
	}
	return (length);
}
