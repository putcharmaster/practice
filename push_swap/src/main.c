/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:47:45 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/24 16:23:10 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	add_n_to_back(t_stack **a_head, int value)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return ;
	new->value = value;
	new->next = NULL;
	if (*a_head == NULL)
	{
		*a_head = new;
		return ;
	}
	last = *a_head;
	while (last->next)
		last = last->next;
	last->next = new;
}

int	ft_lstsize(t_stack *a_head)
{
	t_stack	*tmp;
	int	i;

	tmp = a_head;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	make_stack(char **av, t_stack **a_head)
{
	int	i;
	int	j;
	int		n;

	char	**split;

	i = 1;
	while (av[i])
	{
		split = ft_split(av[i], ' ');
		if (split == NULL)
			return ;
		j = 0;
		while (split[j])
		{
			n = ft_atol(split[j]);
			add_n_to_back(a_head, n);
			j++;
		}
		free_av(split);
		i++;
	}
}

int		is_dup(t_stack *a)
{
	t_stack	*current;
	t_stack *runner;

	current = a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (runner->value == current->value)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || !valid_input(ac, av))
	{
		print_error();
		return (1);
	}
	make_stack(av, &a);
	if (is_dup(a))
	{
		print_error();
		free_stack(a);
		return (1);
	}
	if (is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	algo(&a, &b);
	free_stack(a);
	return (0);
}
