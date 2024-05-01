/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:25:54 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 23:29:32 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	tmp;
	t_list	*start;

	start = lst;
	while (lst->next)
	{
		if (((*cmp)(lst->data, lst->next->data))== 0)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = start;
		}
		else
			lst = lst->next;
	}
	lst = start;
	return (lst);
}
