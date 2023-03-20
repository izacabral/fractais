
#include "mylibc.h"

static int	is_digit_base(char c)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (my_tolower(c) != base[i] && base[i])
		i++;
	return (i);
}

int	my_atoi_base(char *str, int str_base)
{
	int	number;
	int	signal;
	int	digit;

	number = 0;
	signal = 1;
	digit = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signal *= -1;
		str++;
	}
	while (*str && (str_base >= 2 && str_base <= 16))
	{
		digit = is_digit_base(*str);
		if (digit >= 0)
		{
			number = number * str_base;
			number = number + digit;
		}
		++str;
	}
	return (number * signal);
}
