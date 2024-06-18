/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:19:59 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/18 14:10:26 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	init_stack(t_list **a, int ac, char **av)
{
	int		i;
	int		j;
	t_list	*new;
	char	**input;

	i = 1;
	if (!input_check(ac, av))
		error_exit();
	while (i < ac && input_check(ac, av))
	{
		input = ft_split(av[i], ' ');
		j = 0;
		while (input[j])
		{
			new = ft_lstnew(ft_atol(input[j]));
			ft_lstadd_back(a, new);
			j++;
		}
		free_av(input);
		i++;
	}
	index_stack(a);
}

static void	sort_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) < 5)
		simple_sort(a, b);
	else
		radix_sort(a, b);
}

static void	dup_check(t_list *a)
{
	t_list	*current;
	t_list	*runner;
	int		value_to_compare;

	current = a;
	while (current)
	{
		value_to_compare = current->value;
		runner = current->next;
		while (runner)
		{
			if (runner->value == value_to_compare)
			{
				free_stack(&a);
				error_exit();
			}
			runner = runner->next;
		}
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac == 1)
		return (1);
	a = NULL;
	b = NULL;
	init_stack(&a, ac, av);
	dup_check(a);
	if (a == NULL || is_sorted(a) || ft_lstsize(a) == 1)
	{
		free_stack(&a);
		return (0);
	}
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
