/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:05:50 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 15:09:01 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_list
{
	struct s_list	*next;
	void		*data;
}		t_list;

int	ft_list_size(t_list *begin_list)
{
	if(begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}
