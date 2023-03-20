
#include "mylibc.h"

void	*my_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	filled;

	filled = count * size;
	ptr = malloc (filled);
	if (ptr == NULL)
		return (NULL);
	my_bzero(ptr, filled);
	return (ptr);
}
