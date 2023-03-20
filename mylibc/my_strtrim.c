
#include "mylibc.h"

char	*my_strtrim(char const *s1, char const *set)
{
	char	*trimed;
	size_t	start;
	size_t	end;
	size_t	length;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && my_strchr(set, s1[start]))
	{
		start++;
	}
	end = my_strlen(s1);
	while (s1[end - 1] && my_strchr(set, s1[end - 1]) && end > start)
	{
		end--;
	}
	length = end - start;
	trimed = my_substr(s1, start, length);
	return (trimed);
}
