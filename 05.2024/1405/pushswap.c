/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:34:12 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/16 14:08:21 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	chek_arg_for_nan(char **split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (split[i])
	{
		j = 0;
		while ((split[i][j] == '+' || split[i][j] == '-')
			&& split[i][j])
			j++;
		if (j > 1 || split[i][j] == '\0')
			return (0);
		while (split[i][j])
		{
			if (split[i][j] < '0' || split[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	sb(t_list **lst, int i)
{
	t_list	*first;
	t_list	*second;

	if (!*lst || !(*lst)->next)
		return ;
	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
	if (i == 0)
		write(1, "sb\n", 3);
}

void	rb(t_list **b, int i)
{
	t_list	*first;
	t_list	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = (*b)->next;
	last->next = first;
	first->next = NULL;
	if (i == 0)
		write(1, "rb\n", 3);
}

void	rrb(t_list **b, int i)
{
	t_list	*last;
	t_list	*first;
	t_list	*second;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = *b;
	while (second->next->next)
		second = second->next;
	last = second->next;
	*b = last;
	last->next = first;
	second->next = NULL;
	if (i == 0)
		write(1, "rrb\n", 4);
}

void	sa(t_list **lst, int i)
{
	t_list	*first;
	t_list	*scnd;

	if (!*lst || !(*lst)->next)
		return ;
	first = *lst;
	scnd = first->next;
	first->next = scnd->next;
	scnd->next = first;
	*lst = scnd;
	if (i == 0)
		write(1, "sa\n", 3);
}

void	pa(t_list **a, t_list **b, int i)
{
	t_list	*top_b;

	if (!*b)
		return (0);
	top_b = *b;
	*b = (*b)->next;
	top_b->next = (*a);
	*a = top_b;
	if (i == 0)
		write(1, "pa\n", 3);
}

void	ra(t_list **a, int i);
{
	t_list	*first;
	t_list	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = (*a)->next;
	last->next = first;
	first->next = NULL;
	if (i == 0)
		write(1, "ra\n", 3);
}

void	rra(t_list **a, int i)
{
	t_list	*last;
	t_list	*first;
	t_list	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = *a;
	while (second->next->next)
		second = second->next;
	last = second->next;
	*a = last;
	last->next = first;
	second->next = NULL;
	if (i == 0)
		write(1, "rra\n", 4);
}


void	sort_b(t_list **a, t_list **b)
{
	if (ft_lstsize(a) > 3 && !(check_sorted(a)))
		pb(b, a, 0);
	if (ft_lstsize(a) > 3 && !(check_sorted(a)))
		pb(b, a, 0);
	if (ft_lstsize(a) > 3 && !(check_sorted(a)))
		sort_b_until_a_has_three(a, b);
	if (!(check_sorted(a)))
		sort_three(a);
}

void	push_two_lowest_to_b(t_list **a, t_list **b)
{
	int	low_idx;
	int	op_ra;
	int	op_rra;

	while (ft_lstsize(a) > 3)
	{
		op_ra = 0;
		op_rra = 0;
		low_idx = find_index(a, find_minimum_value(a));
		if (low_idx <= ft_lstsize(a) / 2)
			op_ra = low_idx;
		else
			op_rra = ft_lstsize(a) - low_idx;
		while (--op_ra > -1)
			ra(a, 0);
		while (--op_rra > -1)
			rra(a, 0);
		pb(b, a, 0);
	}
}

void	push_two_lowest_to_a(t_list **a, t_list **b)
{
	while (ft_lstsize(b))
		pa(a, b, 0);
}

void	sort_five(t_list **a, t_list **b)
{
	push_two_lowest_to_b(a, b);
	if (!check_sorted(a))
		sort_three(a);
	push_two_lowest_to_a(a, b);
}

void	sort_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(a) == 2)
	{
		sa(a, 0);
		return ;
	}
	else if (ft_lstsize(a) == 5)
		sort_five(a, b);
	else
	{
		sort_b(a, b);
		sort_a(a, b);
	}
}

void	free_list(t_list **lst)
{
	t_list	*cur;
	t_list	*temp;

	cur = *lst;
	while (cur)
	{
		temp = cur;
		cur = cur->next;
		free(temp);
	}
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
}

int	ft_lstsize(t_list **lst)
{
	int	i;
	t_list	*cur;

	cur = *lst;
	i = 0;
	while (cur)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}

typedef struct	s_list
{
	int		content;
	struct s_list	*next;
}		t_list;

int	check_sorted(t_list **a)
{
	t_list	*cur;
	int	cmp;

	if (!*a || !(*a)->next)
		return (1);
	cur = *a;
	cmp = cur->content;
	cur = cur->next;
	while (cur)
	{
		if (cmp > cur->content)
			return (0);
		cmp = cur->content;
		cur = cur->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (ac > 1 && !(av_error(ac, av)))
		return (ft_print_error());
	ft_init_stack(&a, ac, av);
	if (ft_lstsize(&a) == 1)
	{
		free_list(&a);
		return (0);
	}
	if (!(check_sorted(&a)))
		sort_stack(&a, &b);
	free_list(&a);
	return (0);
}
