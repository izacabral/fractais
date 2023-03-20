
#include "mylibc.h"

char	*my_strrchr(const char *s, int c)
{
	int	index;

	index = my_strlen(s);
	while (index >= 0)
	{
		if (s[index] == (char)c)
			return ((char *) &s[index]);
		index--;
	}
	return (NULL);
}
