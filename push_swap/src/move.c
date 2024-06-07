
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:00:15 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/07 10:00:17 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    move(t_stack **a, t_stack **b)
{
    int min;

    min = find_min_value(*a);
    //find index of value;

}

int     find_index(t_stack *a, int min)
{
    int index;

    index = 0;
    while (a)
    {
        if (a->value == min)
            return (index);
        index++;
        a = a->next;
    }
}

int    move_to_top_cost(t_stack **a, int index)
{
    int size;

    size = stack_size(a);
    if (index < size / 2)
        return (index); // ra
    else
        return (size - index); // rra
}

void    move_to_top(t_stack **a, int index)
{
    int size;
    size = stack_size(a);

    if (index < size / 2)
        while (index--)
            ra(a);
    else
        while (index--)
            rra(a);
}