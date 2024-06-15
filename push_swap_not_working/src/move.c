
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
    t_best *best;
    best = find_optimal_nodes(*a, *b);
    int optimal;
    //int max;
    int index;
    int a_size;
    int b_size;
  
    a_size = stack_size(*a);
    while (a_size--)
    {
        optimal = best->a->value;
        index = find_index(*a, optimal);
        move_to_top(a, index, 'a');
        pb(a, b);
    }
    b_size = stack_size(*b);
    while (b_size--)   
        pa(b, a);
}

/*
void    move(t_stack **a, t_stack **b)
{
    //int min;
    int max;
    int index;
    int a_size;
    int b_size;
  
    a_size = stack_size(*a);
    while (a_size--)
    {
     //   min = find_min_value(*a);
      //  index = find_index(*a, min);
      //  move_to_top(a, index);
        pb(a, b);
    }
    b_size = stack_size(*b);
    while (b_size--)
    {
        max = find_max_value(*b);
        index = find_index(*b, max);
        move_to_top(b, index, 'b');
        pa(b,a);
    }
}*/

/*
int    move_to_top_cost(t_stack **a, int index)
{
    int size;

    size = stack_size(a);
    if (index < size / 2)
        return (index); // ra
    else
        return (size - index); // rra
}
*/

void    move_to_top(t_stack **stack, int index, char stack_id)
{
    int size;
    size = stack_size(*stack);

    if (index <= size / 2)
        while (index--)
        {
            if (stack_id == 'a')
                ra(stack);
            else
                rb(stack);
        }
    else
    {   //index = size - index;
        while (index++ < size)
        {
            if (stack_id == 'a')
                rra(stack);
            else
                rrb(stack);
        }
    }
}

