#include "../inc/push_swap.h"

void rotate_b_to_position(t_stack **b, int value)
{
    int index;
    int size_b;

    size_b = stack_size(*b);
    index = find_index(*b, value);

    if (is_upper_half(*b, value))
    {
        while (index--)
            rb(b);
    }
    else
    {
        while (size_b - index)
            rrb(b);
    }
}

void push_to_b(t_stack **a, t_stack **b, t_stack *optimal_a)
{
    int index;
    int size_a;
    //int cost_a;
    int cost_b;

    size_a = stack_size(*a);
    index = find_index(*a, optimal_a->value);
    //cost_a = cost_to_top(*a, optimal_a->value);

    // Rotate stack A to bring optimal_a to the top
    if (is_upper_half(*a, optimal_a->value))
    {
        while (index--)
            ra(a);
    }
    else
    {
        while (size_a - index)
            rra(a);
    }

    // Find the optimal position in stack B and rotate B accordingly
    t_best *optimal_nodes = find_optimal_nodes(*a, *b);
    cost_b = cost_to_top(*b, optimal_nodes->b->value);

    if (is_upper_half(*b, optimal_nodes->b->value))
    {
        while (cost_b--)
            rb(b);
    }
    else
    {
        while (stack_size(*b) - cost_b)
            rrb(b);
    }

    // Push from A to B
    pb(a, b);
}
/*
void push_to_b(t_stack **a, t_stack **b, t_stack *optimal_a)
{
    int index;
    int size_a;
    //int size_b;
    //int cost;

    size_a = stack_size(*a);
    //size_b = stack_size(*b);
    index = find_index(*a, optimal_a->value);
    //cost = cost_to_top(*a, optimal_a->value);
    if (is_upper_half(*a, optimal_a->value))
    {
        while (index--)
            ra(a);
    }
    else
    {
        while (size_a - index)
            rra(a);
    }
    pb(a, b);

}
*/

void push_a_to_b(t_stack **a, t_stack **b) 
{
  
    while (*a) {
        t_best *optimal_nodes = find_optimal_nodes(*a, *b);
        if (!optimal_nodes) {
           return;
        }
        
        push_to_b(a, b, optimal_nodes->a);
        free(optimal_nodes);
    }
}


t_stack	*find_match_in_a(t_stack *a, int b_value)
{
	t_stack	*a_match;

	a_match = NULL;
	while (a)
	{
		if (a->value > b_value && 
            (!a_match || a->value < a_match->value))
			a_match = a;
		a = a->next;
	}
	return (a_match);
}


void	create_pair(t_best **head, t_best **tail, t_stack *a, t_stack *b)
{
	t_best	*new_pair;

	new_pair = (t_best *)malloc(sizeof(t_best));
	new_pair->a = a;
	new_pair->b = b;
	new_pair->next = NULL;
	if (!*head)
	{
		*head = new_pair;
		*tail = new_pair;
	}
	else
	{
		(*tail)->next = new_pair;
		*tail = new_pair;
	}
}

t_best	*best_combination(t_stack *a, t_stack *b)
{
	t_best	*head;
	t_best	*tail;
	t_stack	*a_match;

	head = NULL;
	tail = NULL;
	while (b)
	{
		a_match = find_match_in_a(a, b->value);
		if (a_match)
			create_pair(&head, &tail, a_match, b);
		b = b->next;
	}
	return (head);
}
t_best	*find_optimal_nodes(t_stack *a, t_stack *b)
{
	t_best	*pairs;
	t_best	*optimal;
	t_best	*result;

	pairs = best_combination(a, b);
	optimal = find_smaller_cost(pairs, a, b);
	result = NULL;
	if (optimal)
	{
		result = (t_best *)malloc(sizeof(t_best));
		if (!result)
			return (NULL);
		*result = *optimal;
		result->next = NULL;
	}
	free_pairs(pairs);
	return (result);
}

t_best	*find_smaller_cost(t_best *optimal, t_stack *a, t_stack *b)
{
	t_best	*best_cost;
	t_best	*current;

	best_cost = optimal;
	current = optimal;
	if (optimal == NULL)
		return (NULL);
	best_cost->cost = cost_to_top(a, current->a->value)
		+ cost_to_top(b, current->b->value);
	current->cost = best_cost->cost;
	current = current->next;
	while (current)
	{
		current->cost = cost_to_top(a, current->a->value)
			+ cost_to_top(b, current->b->value);
		if (current->cost < best_cost->cost)
			best_cost = current;
		current = current->next;
	}
	return (best_cost);
}

int     is_upper_half(t_stack *stack, int value)
{
    int index;
    int size;

    index = find_index(stack, value);
    size = stack_size(stack);
    if (index > size / 2)
        return (1);
    return (0);
}

int     cost_to_top(t_stack *stack, int value)
{
    int index;
    int size;
    int cost;

    index = find_index(stack, value);
    size = stack_size(stack);
    if (index > size / 2)
        cost = size - index;
    else
        cost = index;
    return (cost);
}