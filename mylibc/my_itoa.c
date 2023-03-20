
#include "mylibc.h"

static int	my_count(int n)
{
	int			digits;
	long int	aux_n;

	digits = 0;
	aux_n = n;
	if (aux_n < 0)
	{
		digits++;
		aux_n = aux_n * -1;
	}
	while (aux_n > 9)
	{
		aux_n = aux_n / 10;
		digits++;
	}
	digits++;
	return (digits);
}

char	*my_itoa(int n)
{
	char		*str;
	long		end;
	long int	aux_n;

	end = my_count(n);
	str = malloc((end + 1) * sizeof(char));
	if (!str)
		return (NULL);
	aux_n = n;
	if (aux_n < 0)
		aux_n = aux_n * -1;
	str[end] = '\0';
	end--;
	while (end >= 0)
	{
		str[end] = (aux_n % 10) + '0';
		aux_n = aux_n / 10;
		end--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/* int main(void)
{
	int number = 2147483647;
	printf("N.º caracter Max int: %d\n", my_count(number));
	char *str_my_itoa;
	str_my_itoa = my_itoa(number);
	printf("INT MAX to string: %s\n\n", str_my_itoa);
	int number2 = -2147483648;
	printf("N.º caracter Min int: %d\n", my_count(number2));
	str_my_itoa = my_itoa(number2);
	printf("INT MIN to string: %s\n\n", str_my_itoa);
	int number3 = 0;
	printf("N.º caracter 0: %d\n", my_count(number3));
	str_my_itoa = my_itoa(number3);
	printf("0 to string: %s\n\n", str_my_itoa);
}
 */
