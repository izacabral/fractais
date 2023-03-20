
#include "mylibc.h"

int	my_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	index = 0;
	if (n > 0)
	{
		while (index < n - 1 && (str1[index] == str2[index]))
		{
			index++;
		}
		return (str1[index] - str2[index]);
	}
	return (0);
}
