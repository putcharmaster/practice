/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:19:59 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/17 16:27:12 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


static void		init_stack(t_list **a, int ac, char **av)
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

/*
{
	int		i;
	int		j;
	t_list	*new;
	char	**input;

	i = 0;
	if (ac == 2)
		input = ft_split(av[1], ' ');
	else
	{
		i = 1;
		input = av;
	}
	while (input[i])
	{
		new = ft_lstnew(ft_atol(input[i]));
		ft_lstadd_back(a, new);
		i++;
	}
	index_stack(a);
	if (ac == 2)
		free_av(input);
}*/



/*
static void		init_stack(t_list **a, char **av)
{
        t_list  *new;
        char    **split;
        int     i;
        int     j;

        i = 1;
        while (av[i])
        {
                split = ft_split(av[i], ' ');
                if (split == NULL)
                        return ;
                j = 0;
                while (split[j])
                {
                        new = ft_lstnew(ft_atol(split[j]));
                        ft_lstadd_back(a, new);
                        j++;
                }
                free_av(split);
                i++;
        }
        index_stack(a);
}
*/

static void	sort_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) < 5)
		simple_sort(a, b);
	else
		radix_sort(a, b);
}
static void	dup_check(t_list *a)
{
	t_list 	*current;
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
	//if (!input_check(ac, av))
	//	error_exit();
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
	free_stack(&b); // check if it's needed
	return (0);
}
