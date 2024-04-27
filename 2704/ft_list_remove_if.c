/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:03:42 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/27 14:15:01 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return;
	t_list *move;

	move = *begin_list;
	if (cmp(move->data, data_ref) == 0)
	{
		*begin_list = move->next;
		free(move);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		move = *begin_list;
		ft_list_remove_if(&move->next, data_ref, cmp);
	}
}
