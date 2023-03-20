
#include "mylibc.h"

void	my_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst)
	{
		(f)(lst->content);
		lst = lst->next;
	}	
}

/* 
#include <stdio.h>
void printlst(t_list *node)
{
	while(node)
	{
		printf("%s\n", node ->content);
		node = node -> next;
	}
}

char get_upper(unsigned int i, char c)
{
    i = 0;
    if (my_isalpha(c))
    {
        return (my_toupper(c));
    }
    return (c);
}

void make_upper(void *sqnc)
{
    char *str;
 
    str = (char *) sqnc;
    while(*str != '\0')
    {
        *str = get_upper(0, *str);
        str++;
    }
}

int main(void)
{
	t_list *people;

	char content1[] = "izsoares";
	char content2[] = "antes de izsoares";
	char content3[] = "antes de antes";
	char content4[] = "serei o ultimo?";
	people = my_lstnew(content1);
	my_lstadd_front(&people, my_lstnew(content2));
	my_lstadd_front(&people, my_lstnew(content3));
	my_lstadd_back(&people, my_lstnew(content4));
	printlst(people);
	my_lstiter(people, make_upper);
	printlst(people);
	return (0);
} 
 */