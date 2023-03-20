
#include "mylibc.h"

void	*my_memset(void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*dest;

	index = 0;
	dest = s;
	while (index < n)
	{
		dest[index] = (unsigned char)c;
		index++;
	}
	return (dest);
}
