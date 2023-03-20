
#include "mylibc.h"

size_t	my_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	index;

	srclen = my_strlen(src);
	index = 0;
	if (srclen + 1 < size)
	{
		while (index < srclen +1)
		{
			dst[index] = src[index];
			index++;
		}
	}
	else if (size != 0)
	{
		index = 0;
		while (index < size - 1)
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (srclen);
}
