#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int value;
	struct s_stack *next;
}	t_stack;

int	add_value(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i += a->value;
		a = a->next;
	}
	return (i);
}

int main()
{
        t_stack *a = malloc(sizeof(t_stack));
	t_stack *b = malloc(sizeof(t_stack));

        a->value = 2;
        a->next = b;
	b->value = 4;
	b->next = NULL;

        printf("%p\n", &a);
        printf("%d\n", add_value(a));
        printf("%p\n", &a);

}
