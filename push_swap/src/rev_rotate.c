/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 00:03:29 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/18 14:07:23 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rev_rotate(t_list **head)
{
	t_list	*prev;
	t_list	*last;
	t_list	*tmp;

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

void	rra(t_list **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
