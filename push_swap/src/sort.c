/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:39:01 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/29 14:47:04 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int     is_sorted(t_stack *a)
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

int	stack_size(t_stack **head)
{
	int	i;
	t_stack *tmp;

	i = 0;
	tmp = *head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	make_three_and_sort(t_stack **a_stack, t_stack **b_stack)
{
	int	count;
	//int	mean;
	t_stack	*a;

	a = *a_stack;
	count = stack_size(&a);
	while (count > 3)
	{
		pb(a_stack, b_stack);
		count--;
	}
}

int	find_mean(t_stack **head)
{
	int	mean;
	int	count;
	t_stack	*a;

	mean = 0;
	count = 0;
	a = *head;
	while (a)
	{
		mean += a->value;
		count++;
		a = a->next;
	}
	mean /= count;
	return (mean);
}
