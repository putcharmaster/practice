/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:05:18 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/05 00:18:51 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_min_value(t_stack *stack)
{
	int	min;
	t_stack	*tmp;

	tmp = stack;
	min = stack->value;
	while (tmp)
	{
		if (min > tmp->value)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	find_max_value(t_stack *stack)
{
	int	max;
	t_stack	*tmp;

	tmp = stack;
	max = stack->value;
	while (tmp)
	{
		if (max < tmp->value)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	find_mean_value(t_stack *stack)
{
	int	count;
	int	sum;
	int	mean;
	t_stack	*tmp;

	count = 0;
	sum = 0;
	mean = 0;
	tmp = stack;
	while (tmp)
	{
		count++;
		sum += tmp->value;
		tmp = tmp->next;
	}
	if (count == 0)
		return (0);
	mean = sum / count;
	return (mean);
}
