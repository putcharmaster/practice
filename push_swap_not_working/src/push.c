/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 00:09:12 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/25 12:15:46 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stack **src_top, t_stack **dst_top)
{
	t_stack *tmp;

	if (*src_top == NULL)
		return ;
	tmp = *src_top;
	*src_top = (*src_top)->next;
	tmp->next = *dst_top;
	*dst_top = tmp;
}

void	pa(t_stack **b, t_stack **a)
{
	if (!*b)
		return ;
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
}
