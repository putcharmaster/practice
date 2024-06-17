/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 00:09:12 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/15 21:51:09 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_list **src_top, t_list **dst_top)
{
	t_list *tmp;

	if (*src_top == NULL)
		return ;
	tmp = *src_top;
	*src_top = (*src_top)->next;
	tmp->next = *dst_top;
	*dst_top = tmp;
}

void	pa(t_list **b, t_list **a)
{
	if (!*b)
		return ;
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	if (!*a)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
}
