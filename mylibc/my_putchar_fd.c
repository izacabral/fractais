
#include "mylibc.h"

void	my_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* #include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
int main (void)
{
	int fd = open ("teste", O_RDWR);
	
	my_putchar_fd('c', fd);
} */
