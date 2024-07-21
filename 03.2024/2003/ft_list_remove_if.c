/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:11:48 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/20 10:20:20 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (!begin_list || !(*begin_list))
		return ;

	t_list	*tmp;

	tmp = *begin_list;
	if (com(tmp->data, data_ref) == 0)
	{
		*begin_list = tmp->next;
		free(tmp);
		ft_list_remove_if(begin_list, data_ref, cmp)
	}
	else
	{
		tmp = *begin_list;
		ft_list_remove_if(&tmp->next, data_ref, cmp);
	}	
}
