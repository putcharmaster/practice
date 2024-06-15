#include "../inc/push_swap.h"

int max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}
int min(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

void    pass_two_to_b(t_stack **a, t_stack **b)
{
    if (*a)
        pb(a,b);
    if (*a)
        pb(a,b);
}
void    place_smallest_in_a_on_top(t_stack **a)
{
    int first;
    int second;
    int last;

    first = (*a)->value;
    second = (*a)->next->value;
    last = last_stack_value(*a);
    if (first < second)
    {
        if (first < last)
            return ;
        else
            rra(a);
    }
    else
    {
        if (second < last)
            sa(a);
        else
            rra(a);
    }


}

  void    do_a_pb(t_stack **a, t_stack **b)
    {
        place_smallest_in_a_on_top(a);
        pb(a,b);
    }

/*
int calculate_cost(int index_a, int index_b, int size_a, int size_b)
{
    int ra_count;
    int rb_count;
    int rra_count;
    int rrb_count;
    int cost_rr;
    int cost_rrr;
    int cost_ra_rrb;
    int cost_rra_rb;

    ra_count = index_a;
    rb_count = index_b;
    rra_count = size_a - index_a;
    rrb_count = size_b - index_b;
    cost_rr = max(ra_count, rb_count);
    cost_rrr = max(rra_count, rrb_count);
    cost_ra_rrb = ra_count + rrb_count;
    cost_rra_rb = rra_count + rb_count;
    return (min(min(cost_rr, cost_rrr), min(cost_ra_rrb, cost_rra_rb)));
}

int find_cheapest_move(t_stack *a, t_stack *b, int *index_a, int *index_b) {
    int min_cost = INT_MAX;
    int current_cost;
    int size_a = stack_size(a);
    int size_b = stack_size(b);
    t_stack *current_a = a;
    int i = 0;

    while (current_a) {
        int target_index_b = find_index(b, current_a->value);
        current_cost = calculate_cost(i, target_index_b, size_a, size_b);

        if (current_cost < min_cost) {
            min_cost = current_cost;
            *index_a = i;
            *index_b = target_index_b;
        }

        current_a = current_a->next;
        i++;
    }
    return min_cost;
}

void execute_cheapest_move(t_stack **a, t_stack **b) {
    int index_a, index_b;
    find_cheapest_move(*a, *b, &index_a, &index_b);

    move_to_top(a, index_a, 'a');
    move_to_top(b, index_b, 'b');

    pb(a, b);
}*/