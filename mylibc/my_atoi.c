
#include "mylibc.h"

int	my_atoi(const char *str)
{
	int	number;
	int	index;
	int	signal;

	number = 0;
	index = 0;
	signal = 1;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			signal *= -1;
		index++;
	}
	while (my_isdigit(str[index]))
	{
		number = number + (str[index] - '0');
		index++;
		if (my_isdigit(str[index]))
			number = number * 10;
	}
	return (signal * number);
}
