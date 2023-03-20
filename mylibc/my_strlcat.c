
#include "mylibc.h"

size_t	my_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	index;

	srclen = my_strlen(src);
	dstlen = my_strlen(dst);
	index = 0;
	if (size > 0 && size > dstlen)
	{
		while (src[index] && index < (size - dstlen - 1))
		{
			dst[dstlen + index] = src[index];
			index++;
		}
		dst[dstlen + index] = '\0';
		return (srclen + dstlen);
	}
	return (size + srclen);
}
