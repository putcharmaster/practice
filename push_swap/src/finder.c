#include "../inc/push_swap.h"

int    find_index(t_list *stack, int value)
{
    int     index;

    index = 0;
    while (stack)
    {
        if (stack->value == value)
            return (index);
        index++;
        stack = stack->next;
    }
    return (-1);
}

int     value_of_the_last(t_list *stack)
{
    if (stack == NULL)
        return (-1);
    while (stack->next)
        stack = stack->next;
    return (stack->value);
}

int     find_max_value(t_list *stack)
{
    int     max;

    max = INT_MIN;
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return (max);
}

int     find_min_value(t_list *stack)
{
    int     min;

    min = INT_MAX;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return (min);
}