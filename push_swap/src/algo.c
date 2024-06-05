	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:23:49 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/02 15:01:33 by sanhwang         ###   ########.fr       */
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
int	is_rev_sorted(t_stack *b)
{
	while (b->next)
	{
		if ((b->value) < (b->next->value))
			return (0);
		b = b->next;
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

//void	sort_b(t_stack **a, t_stack **b)


void	algo(t_stack **a, t_stack **b)
{
	if ((!is_sorted(*a)) || (*b) != NULL)
	{
		if (avcount(*a) > 3)
			pb(a, b);
		if (avcount(*a) > 3)
			pb(a, b);
		//get max and min of *b
		//if a_head is min or max, replace and push.
		//
		while(avcount(*a) > 3)
			pb(a, b);	
	}
	//if (!is_sorted(*a))
	//	sort_three(a);
}
