
#include "mylibc.h"

char	*my_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*scpy;
	unsigned int	slen;
	unsigned int	index;

	if (!s)
		return (0);
	slen = my_strlen(s);
	scpy = (char *)malloc((slen + 1) * sizeof(char));
	if (scpy == NULL)
		return (NULL);
	index = 0;
	while (s[index])
	{
		scpy[index] = (*f)(index, s[index]);
		index++;
	}
	scpy[index] = '\0';
	return (scpy);
}

/* #include <stdio.h>
char	test_my_strmapi(unsigned int index, char s)
{
	(void) index;
	s = my_toupper(s);
	return (s);
}

int main(void)
{
	
	const char *str_my_strmapi = "eu quero ser maiuscula";
	const char *str_my_strmapi2;
	str_my_strmapi2 = my_strmapi(str_my_strmapi, test_my_strmapi);
	
	printf("Antes da função: %s\n", str_my_strmapi);
	printf("Depois da função: %s\n", str_my_strmapi2);
} */
