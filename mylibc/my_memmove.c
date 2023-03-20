
#include "mylibc.h"

void	*my_memmove(void *dest, const void *src, size_t n)
{
	char		*memory_dest;
	const char	*memory_src;
	size_t		index;

	memory_dest = dest;
	memory_src = src;
	index = n;
	if (memory_src < memory_dest)
	{
		while (index)
		{
			index--;
			memory_dest[index] = memory_src[index];
		}
		return (dest);
	}
	my_memcpy(dest, src, n);
	return (dest);
}
