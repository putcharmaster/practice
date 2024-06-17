/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:46:14 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/17 23:58:42 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h" // Assuming you have this header file for list operations

// Function to get the maximum number of bits required to represent the maximum index
static int bits_of_max_index(t_list *a) {
    int max_index = a->index;
    int max_bits = 0;

    // Find the maximum index
    while (a) {
        if (max_index < a->index)
            max_index = a->index;
        a = a->next;
    }

    // Calculate the number of bits needed to represent the maximum index
    while (max_index >> max_bits)
        max_bits++;
    return max_bits;
}

void radix_sort(t_list **a, t_list **b) {
    int max_bits = bits_of_max_index(*a);

    // Iterate from the most significant bit to the least significant bit
    for (int i = max_bits - 1; i >= 0; i--) {
        int a_size = ft_lstsize(*a); // Calculate size of list `a` once per bit iteration

        for (int j = 0; j < a_size; j++) {
            // Check if the `i`th bit of the index is set
            if (((*a)->index >> i) & 1)
                ra(a); // Rotate `a` if the bit is 1
            else
                pb(a, b); // Push to `b` if the bit is 0
        }

        // Push everything back from `b` to `a`
        while (ft_lstsize(*b) > 0)
            pa(b, a);
    }
}


/*
#include "../inc/push_swap.h"

static int  bits_of_max_index(t_list *a)
{
    int     max_index;
    int     max_bits;

    max_index = a->index;
    max_bits = 0;
    while (a)
    {
        if (max_index < a->index)
            max_index = a->index;
        a = a->next;
    }
    while (max_index >> max_bits)
        max_bits++;
    return (max_bits);
}
*/
/*
void    radix_sort_msb(t_list **a, t_list **b, int bit)
{
    int     a_size;
    if (bit < 0 || ft_lstsize(*a) < 2)
        return ;

    a_size = ft_lstsize(*a);
    while (a_size--)
    {
        if (((*a)->index >> bit) & 1)
            ra(a);
        else
            pb(a, b);
    }
    radix_sort_msb(a, b, bit - 1);
    while (ft_lstsize(*b) > 0)
        pa(b, a);
}

void    radix_sort(t_list **a, t_list **b)
{
    int     max_bits;

    max_bits = bits_of_max_index(*a);
    radix_sort_msb(a, b, max_bits - 1);
}
*/
/*
{
    int     max_bits;
    int     i;
    int     a_size;

    max_bits = bits_of_max_index(*a);
    i = max_bits - 1;
    while (i >= 0)
    {
        a_size = ft_lstsize(*a);
        while (a_size--)
        {
            if (((*a)->index >> i) & 1)
                ra(a);
            else
                pb(a, b);
        }
        while (ft_lstsize(*b) > 0)
            pa(b, a);
        i--;
    }
}
*/
/*
void    radix_sort(t_list **a, t_list **b)
{
    t_list  *stack;
    int     i;
    int     a_size;
    int     max_bits;

    i = 0;
    max_bits = bits_of_max_index(*a);
    while (i < max_bits)
    {
        a_size = ft_lstsize(*a); // it needs to be updated
        while (a_size--)
        {
            stack = *a; // it needs to be updated as well
            if ((stack->index >> i) & 1)
                ra(a);
            else
                pb(a, b);
        }
        while (ft_lstsize(*b))
            pa(b, a);
        i++;
    }
}
*/

