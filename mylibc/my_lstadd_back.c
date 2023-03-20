
#include "mylibc.h"

void	my_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstnode;

	if (*lst == NULL)
		*lst = new;
	else
	{
		lstnode = *lst;
		while (lstnode->next)
			lstnode = lstnode->next;
		lstnode->next = new;
	}
}

/* 
#include <stdio.h>
void printlst(t_list *node)
{
	while(node)
	{
		printf("%s\n",(char *) node ->content);
		node = node -> next;
	}
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
	return (0);
}
 */
