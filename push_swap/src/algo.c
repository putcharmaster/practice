/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:23:49 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/25 12:38:50 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_sorted(t_stack *a)
{
	if (a == NULL)
		return (1);
	while (a->next)
	{
		if ((a->value) > (a->next->value))
			return (0);
		a = a->next;
	}
	return (1);
}

int	avcount(t_stack *a)
{
	t_stack	*tmp;
	int	i;

	tmp = a;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	algo(t_stack **a, t_stack **b)
{
	if ((!is_sorted(*a)) || (*b) != NULL)
	{
		if (avcount(*a) > 5)
			make_five(a, b);
		if (avcount(*a) <= 5 && !is_sorted(*a))
			sort_five(a, b);
		while ((*b) != NULL)
		{
			bf_on_top(a, b);
			pa(a, b);
		}
	}
}
