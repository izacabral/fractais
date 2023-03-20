
#include "mylibc.h"

char	*my_strjoin_free(char const *s1, char const *s2)
{
	char	*newstr;
	int		indexa;
	int		indexb;

	if (!s1)
		return (my_strdup(s2));
	if (!s2)
		return (my_strdup(s1));
	newstr = malloc ((my_strlen(s1) + my_strlen(s2) + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	indexa = 0;
	indexb = 0;
	while (s1[indexa])
	{
		newstr[indexa] = s1[indexa];
		indexa++;
	}
	while (s2[indexb])
		newstr[indexa++] = s2[indexb++];
	newstr[indexa] = '\0';
	free ((void *) s1);
	return (newstr);
}
