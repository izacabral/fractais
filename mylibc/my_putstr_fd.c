
#include "mylibc.h"

void	my_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

/* #include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
int main (void)
{
	int fd2 = open ("teste2", O_RDWR);
	
	my_putstr_fd("fui para teste2?", fd2);
}
 */
