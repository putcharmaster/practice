/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:13:14 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/18 14:13:17 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_list	*find_min_stack(t_list *a)
{
	t_list	*min;

	min = NULL;
	while (a)
	{
		if ((a->index == -1) && (min == NULL || (a->value < min->value)))
			min = a;
		a = a->next;
	}
	return (min);
}

void	index_stack(t_list **a)
{
	t_list	*stack;
	int		index;

	index = 0;
	stack = find_min_stack(*a);
	while (stack)
	{
		stack->index = index++;
		stack = find_min_stack(*a);
	}
}
