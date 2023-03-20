
#include "mylibc.h"

void	my_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		my_putchar_fd('-', fd);
		nbr = nbr * -1;
	}
	if (nbr > 9)
		my_putnbr_fd(nbr / 10, fd);
	my_putchar_fd((nbr % 10) + '0', fd);
}

/* #include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
int main (void)
{
	int fd4 = open ("teste4", O_RDWR);

	my_putnbr_fd(-2147483648, fd4);
}
 */