
#include "mylibc.h"

t_list	*my_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* 
#include <stdio.h>
int main(void)
{
	t_list *person;
	char *content;
	
	content = "izsoares";
	person = my_lstnew(content);
	printf("%s\n", (char *) person->content);
	printf("%p\n", person->next);
}
 */
