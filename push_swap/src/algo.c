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

int	ft_issorted(t_stack *a)
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

void	sort_three(t_stack **a, int max, int min)
{
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

void	sort_four(t_stack **a, t_stack **b, int max, int min)
{
	if ((*a)->value == min)
	{
		pb(a, b);
		sort_three(a, max, min);
		pa(b, a);
		if (!is_sorted(*a))
			ra(a);
	}
	else if ((*a)->next->value == min) 
	{
		sa(a);
		pb(a, b);
		sort_three(a, max, min);
		pa(b, a);
		if (!is_sorted(*a))
			ra(a);
	}
	else
	{
		move(a, b);
	}
}

void	algo(t_stack **a, t_stack **b)
{
	int	max;
	int	min;

	max = find_max_value(*a);
	min = find_min_value(*a);
	if (*a && !is_sorted(*a))
	//if (*a)) || (*b) != NULL)
	{
		if (stack_size(*a) == 1)
			return ;
		else if (stack_size(*a) == 2)
			ra(a);
		else if (stack_size(*a) == 3)
			sort_three(a, max, min);
		//else if (stack_size(*a) == 4)
		//	sort_four(a, b, max, min);
		else // (stack_size(*a) > 3)
		{
		/*
		while (stack_size(*a) > 0)
			execute_cheapest_move(a, b);
		while (stack_size(*b))
			pa(b, a);*/

			
			while (stack_size(*a))
			{
				if ((*a)->value == min || (*a)->value == max)
				{
					pb(a, b);
					if ((*b)->value < find_min_value(*b))
						rb(b);
				}
				else
					ra(a);
			}
			
		}
			//make_three_and_sort(a, b, max, min);	
	}
	//if (!is_sorted(*a))
	//	sort_three(a);
}
