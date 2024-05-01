/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:27:59 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/21 17:32:32 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (!begin_list || !(*begin_list))
		return ;

	t_list	*start;

	start = *begin_list;
	while (com(start->data, data_ref) == 0)
	{
		*begin_list = start->next;
		free(start);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		start = *begin_list;
		ft_list_remove_if(&start->next, data_ref, cmp);
	}
}
