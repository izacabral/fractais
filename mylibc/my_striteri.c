
void	my_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	if (!s)
		return ;
	index = 0;
	while (s[index])
	{
		(*f)(index, &s[index]);
		index++;
	}
	return ;
}

/* #include <stdlib.h>
#include <stdio.h>

void    my_toupper_iteri(unsigned int i, char* c)
{
    (void) i;
    if (*c >= 'a' && *c <= 'z')
        *c -= 32;
}

int main(void)
{
	
	char str_my_striteri[] = "eu quero ser maiuscula";
	my_striteri(str_my_striteri, my_toupper_iteri);
	printf("%s\n", str_my_striteri);
}
 */