
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

#include <stdio.h>

void    move(t_stack **a, t_stack **b)
{
    int min;
    int index;
    int a_size;
    int b_size;

    a_size = stack_size(*a);
  
    while (a_size-- > 3)
    {
        min = find_min_value(*a);
        index = find_index(*a, min);
        move_to_top(a, index);
        if (!is_sorted(*a))
            pb(a, b);
    }
    if (!is_sorted(*a))
        sort_three(a, find_max_value(*a), find_min_value(*a));
      b_size = stack_size(*b);
      
    //erase this  
      //printf("b_size: %d\n", b_size);
    
    
    while (b_size--)   
        pa(a, b);
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
    return (-1);
}
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

void    move_to_top(t_stack **a, int index)
{
    int size;
    size = stack_size(*a);

    if (index <= size / 2)
        while (index--)
            ra(a);
    else
    {   //index = size - index;
        while (index++ < size)
            rra(a);
    }
}