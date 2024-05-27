/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 00:03:29 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/25 00:08:52 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rev_rotate(t_stack **head)
{
	t_stack	*prev;
	t_stack *last;
	t_stack	*tmp;

	prev = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	tmp = last;
	prev->next = NULL;
	tmp->next = *head;
	*head = tmp;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
