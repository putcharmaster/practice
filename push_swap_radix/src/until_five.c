/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   until_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:46:24 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/17 03:51:53 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void    sort_four(t_list **a, t_list **b, int min)
{
    int     index;

    index = find_index(*a, min);
    if (index == 0)
        pb(a, b);
    else
    {
        if (index < ft_lstsize(*a) / 2)
        {
            while (index-- > 0)
                ra(a);
        }
        else
        {
            while (index++ < ft_lstsize(*a))
                rra(a);
        }
        pb(a, b);
    }
    sort_three(a);
    pa(b, a);
}

void    sort_three(t_list **a)
{
    int     max;
    int     min;

    max = find_max_value(*a);
    min = find_min_value(*a);
    if ((*a)->value != min && (*a)->next->value == max)
        rra(a);
    else if ((*a)->value == min)
    {
        sa(a);
        ra(a);
    }
    else if ((*a)->value == max && (*a)->next->value == min)
            ra(a);
    else if ((*a)->value == max && (*a)->next->next->value == min)
    {
            ra(a);
            sa(a);
    }
    else if ((*a)->value != min && (*a)->next->next->value == max)
            sa(a);
}

void    simple_sort(t_list **a, t_list **b)
{
    int     min;
    
    min = find_min_value(*a);
    if (ft_lstsize(*a) == 4)
        sort_four(a, b, min);
    else if (ft_lstsize(*a) == 3)
        sort_three(a);
    else if (ft_lstsize(*a) == 2)
        ra(a);
    
    
    //else
      //  radix_sort(a, b);
}
