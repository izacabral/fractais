
#include "mylibc.h"

void	my_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

/* 
#include <stdio.h>
void	printlst(t_list *node)
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
	
	content1 = "izsoares";
	content2 = "antes de izsoares";
	people = my_lstnew(content1);
	my_lstadd_front(&people, my_lstnew(content2));
	printlst(people);
	return (0);
}
 */