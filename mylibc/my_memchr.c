
#include "mylibc.h"

void	*my_memchr(const void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*bcpy;

	bcpy = (unsigned char *) b;
	index = 0;
	while (index < len)
	{
		if (bcpy[index] == (unsigned char) c)
			return ((unsigned char *) &bcpy[index]);
		index++;
	}
	return (NULL);
}
