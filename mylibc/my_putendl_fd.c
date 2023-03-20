
#include "mylibc.h"

void	my_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

/* #include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
int main (void)
{
	int fd3 = open ("teste3", O_RDWR);
	
	my_putendl_fd("fui para teste3 com quebra?", fd3);
} */
