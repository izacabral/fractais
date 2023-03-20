
#include "mylibc.h"

void	my_bzero(void *s, size_t n)
{
	my_memset((void *) s, 0, (size_t) n);
}
