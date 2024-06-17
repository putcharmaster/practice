/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:57:40 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/15 21:44:10 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	tmp = (*head)->next;
	(*head)->next = NULL;
	last->next = *head;
	*head = tmp;
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
