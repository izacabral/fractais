
#include "mylibc.h"

char	*my_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	if (!s)
		return (NULL);
	while (s[index] != (char)c)
	{
		if (s[index] == '\0')
			return (NULL);
		index++;
	}
	return ((char *) &s[index]);
}
