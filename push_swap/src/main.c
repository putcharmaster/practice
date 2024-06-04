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

int	valid_input(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+' || av[i][j] == ' ')
				j++;
			if (!is_digit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sorted(t_stack *a)
{
	if (a = NULL)
		return (1);
	while (a->next)
	{
		if ((a->value) > (a->next->value))
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

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

void	split_av(char **av, t_stack **a_head)
{
	int	i;
	int	j;
	long	n;
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
			if (out_of_int(n))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			add_n_to_back(a_head, n);
			j++;
		}
		free_av(split);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || !valid_input(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	split_av(av, &a);
	//check 
	if (is_sorted(a))
		return (0);
	algo(&a, &b);
	free_stack(a);
	return (0);
}
