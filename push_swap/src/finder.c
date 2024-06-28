/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:12:18 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/19 21:07:51 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	min_to_top(t_list **a)
{
	int	min;
	int	index;

	min = find_min_value(*a);
	index = find_index(*a, min);
	if (index < ft_lstsize(*a) / 2)
		while (index--)
			ra(a);
	else
		while (index++ < ft_lstsize(*a))
			rra(a);
}

int	find_index(t_list *stack, int value)
{
	int	index;

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

int	value_of_the_last(t_list *stack)
{
	if (stack == NULL)
		return (-1);
	while (stack->next)
		stack = stack->next;
	return (stack->value);
}

int	find_max_value(t_list *stack)
{
	int	max;

	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	find_min_value(t_list *stack)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}
