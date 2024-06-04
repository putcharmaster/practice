#include <stdio.h>

typedef struct s_stack
{
	int	value;
	struct s_stack *next;
}	t_stack

void	modify_stack(t_stack *a)
{
	a->value = 42;

	t_stack	new;

	new->value = 99;
	a = &new;
}
