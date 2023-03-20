
#include "mylibc.h"

void	*my_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstcpy;
	const char	*srccpy;
	size_t		index;

	dstcpy = dst;
	srccpy = src;
	index = 0;
	if (src == NULL && dst == NULL)
		return (dst);
	while (n > index)
	{
		dstcpy[index] = srccpy[index];
		index++;
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
char str_my_memcpy1[50] = "eu sou a string 1";
char str_my_memcpy2[50] = "\0";

char str_memcpy1[50] = "eu sou a string 1";
char str_memcpy2[50] = "\0";

	printf("*****CREATED*****\n");
	printf("str_my_memcpy1 before my_memcpy() is: %s\n\n", str_my_memcpy1);
	my_memcpy(str_my_memcpy1, str_my_memcpy2, sizeof(str_my_memcpy2));
	printf("str_my_memcpy1 amyer my_memcpy() is: %s\n\n", str_my_memcpy1);
	
	printf("\n*****ORIGINAL*****\n");
	printf("str_memcpy1 before memcpy() is: %s\n\n", str_memcpy1);
	memcpy(str_memcpy1, str_memcpy2, sizeof(str_memcpy2));
	printf("str_memcpy1 amyer memcpy() is: %s\n\n", str_memcpy1);

}
*/
