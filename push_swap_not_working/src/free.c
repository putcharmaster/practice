/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 00:32:06 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/14 14:56:59 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

void	free_stack(t_stack *head)
{
	t_stack	*tmp;
	
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}


void	free_pairs(t_best *pairs)
{
	t_best	*tmp;

	while (pairs)
	{
		tmp = pairs;
		pairs = pairs->next;
		free(tmp);
	}
}
