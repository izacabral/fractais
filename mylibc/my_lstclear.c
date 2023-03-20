
#include "mylibc.h"

void	my_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lstaux;

	if (!lst)
		return ;
	lstaux = *lst;
	while (*lst)
	{
		lstaux = (*lst)->next;
		my_lstdelone((*lst), del);
		*lst = lstaux;
	}
	*lst = NULL;
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

void my_del(void *content)
{
	content = 0;
}


int main(void)
{
	t_list *people;
	char *content1;
	char *content2;
	char *content3;
	char *content4;
	
	content1 = "izsoares";
	content2 = "antes de izsoares";
	content3 = "antes de antes";
	content4 = "serei o ultimo?";
	people = my_lstnew(content1);
	my_lstadd_front(&people, my_lstnew(content2));
	my_lstadd_front(&people, my_lstnew(content3));
	my_lstadd_back(&people, my_lstnew(content4));
	printlst(people);
	my_lstclear(&people, my_del);
	printlst(people);
	return (0);
} 
 */
