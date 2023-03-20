
#include "mylibc.h"

t_list	*my_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;

	newnode = NULL;
	newlst = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		newnode = my_lstnew((*f)(lst->content));
		if (!newnode)
		{
			my_lstclear(&newlst, del);
			return (NULL);
		}
		my_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
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

void *make_upper_2(void *sqnc)
{
    char *str;
 
    str = (char *) sqnc;
    make_upper(str);
    return (str);
}

void    del_content(void *pointer)
{
    printf("deleted %p\n", pointer);
}

int main(void)
{
	t_list *people;
	t_list *people2;

	char content1[] = "izsoares";
	char content2[] = "antes de izsoares";
	char content3[] = "antes de antes";
	char content4[] = "serei o ultimo?";
	people = my_lstnew(content1);
	my_lstadd_front(&people, my_lstnew(content2));
	my_lstadd_front(&people, my_lstnew(content3));
	my_lstadd_back(&people, my_lstnew(content4));
	printlst(people);
	people2 = my_lstmap(people, make_upper_2, del_content);
	printlst(people2);
	return (0);
} 
 */
