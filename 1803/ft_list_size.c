/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:42:30 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/18 16:50:19 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                t_list;



int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while(begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}


int	ft_list_size1(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	else
		return (ft_list_size1(begin_list->next) + 1);
}


