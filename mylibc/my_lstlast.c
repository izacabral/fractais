
#include "mylibc.h"

t_list	*my_lstlast(t_list *lst)
{
	t_list	*aux;

	if (!lst)
		return (NULL);
	aux = lst;
	while (aux->next)
	{
		aux = aux -> next;
	}
	return (aux);
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
	char *lastcontent;
	
	content1 = "izsoares";
	content2 = "antes de izsoares";
	content3 = "antes de antes";
	people = my_lstnew(content1);
	my_lstadd_front(&people, my_lstnew(content2));
	my_lstadd_front(&people, my_lstnew(content3));
	printlst(people);
	printf("lstlast:%s\n", *my_lstlast(people));
	return (0);
}
 */
