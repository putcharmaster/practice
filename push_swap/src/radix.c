/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:46:14 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/18 14:06:48 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	bits_of_max_index(t_list *a)
{
	int	max_index;
	int	max_bits;

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

void	radix_sort(t_list **a, t_list **b)
{
	t_list	*stack;
	int		i;
	int		a_size;
	int		max_bits;

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
