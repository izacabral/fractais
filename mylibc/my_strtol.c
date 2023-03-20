
#include "mylibc.h"

static int	get_digit(char c)
{
	c = my_tolower(c);
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	else
		return (37);
}

static int	get_base(const char *nptr, int base)
{
	if (base == 0)
	{
		if (*nptr == '0')
		{
			base = 8;
			nptr++;
			if (*nptr == 'x' || *nptr == 'X')
				base = 16;
		}
		else
			base = 10;
	}
	return (base);
}

static const char	*get_nptr(const char *nptr, int base)
{
	const char	*ptr;

	ptr = nptr;
	if (base == 16 && *ptr == '0')
	{
		ptr++;
		if (*ptr == 'x' || *ptr == 'X')
			ptr++;
	}
	return (ptr);
}

static long	get_result(const char *nptr, char **endptr, int base, int negative)
{
	int		digit;
	long	result;

	result = 0;
	digit = 0;
	while (*nptr && get_digit(*nptr) <= base)
	{
		digit = get_digit(*nptr);
		result = result * base;
		result = result + digit;
		if (result < 0)
		{
			if (endptr)
				*endptr = (char *) nptr;
			return (MY_LONG_MAX + negative);
		}
		nptr++;
	}
	if (endptr)
		*endptr = (char *) nptr;
	return (result + (result * -2 * negative));
}

long	my_strtol(const char *nptr, char **endptr, int base)
{
	int		negative;
	long	result;

	if (base < 0 || base > 36)
		return (0);
	negative = 0;
	result = 0;
	if (base == 0 || (base >= 2 && base <= 36))
	{
		while (my_isspacetab(*nptr))
			nptr++;
		if (*nptr == '-' || *nptr == '+')
		{
			if (*nptr == '-')
				negative = 1;
			nptr++;
		}
		base = get_base(nptr, base);
		nptr = get_nptr(nptr, base);
		result = get_result (nptr, endptr, base, negative);
	}
	return (result);
}

/*
int main (void)
{
	printf("my_strtol 0XFF: %ld\n", my_strtol("0XFF", (char **) NULL, 0));
	printf("strtol 0XFF: %ld\n", strtol("0XFF", (char **) NULL, 0));
	printf("my_strtol 060: %ld\n", my_strtol("060", (char **) NULL, 0));
	printf("strtol 060: %ld\n", strtol("060", (char **) NULL, 0));
	printf("my_strtol 0060: %ld\n", my_strtol("0060", (char **) NULL, 0));
	printf("strtol 0060: %ld\n", strtol("0060", (char **) NULL, 0));
	printf("my_strtol FF: %ld\n", my_strtol("FF", (char **) NULL, 16));
	printf("strtol FF: %ld\n", strtol("FF", (char **) NULL, 16));
	printf("my_strtol 060: %ld\n", my_strtol("060", (char **) NULL, 16));
	printf("strtol 060: %ld\n", strtol("060", (char **) NULL, 16));
	printf("my_strtol 060: %ld\n", my_strtol("060", (char **) NULL, 10));
	printf("strtol 060: %ld\n", strtol("060", (char **) NULL, 10));
	printf("my_strtol 60: %ld\n", my_strtol("60", (char **) NULL, 0));
	printf("strtol 60: %ld\n", strtol("60", (char **) NULL, 0));
	printf("my_strtol 60: %ld\n", my_strtol("60", (char **) NULL, 1));
	printf("strtol 60: %ld\n", strtol("60", (char **) NULL, 1));
}
*/
