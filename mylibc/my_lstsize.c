
#include "mylibc.h"

int	my_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{	
		lst = lst -> next;
		size++;
	}
	return (size);
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
	
	content1 = "izsoares";
	content2 = "antes de izsoares";
	content3 = "antes de antes";
	people = my_lstnew(content1);
	my_lstadd_front(&people, my_lstnew(content2));
	my_lstadd_front(&people, my_lstnew(content3));
	printlst(people);
	printf("lstsize:%d\n", my_lstsize(people));
	return (0);
}
 */
