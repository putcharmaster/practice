#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int	content;
	struct s_list	*next;
}	t_list;

int	listsize(t_list *lst)
{
	int	i;
	i = 0;
	while (lst){
		lst = lst->next;
		i++;}
	return (i);
}


int	main()
{
	t_list	*t1 = malloc(sizeof(t_list));
	
	t1->content = 2;
	printf("size: %d\n", listsize(t1));
	free(t1);
	return (0);
}
