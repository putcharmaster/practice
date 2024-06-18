/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:22:05 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/18 13:53:04 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

//finder.c
int		find_max_value(t_list *stack);
int		find_min_value(t_list *stack);
int		value_of_the_last(t_list *stack);
int		find_index(t_list *stack, int value);

//input.c
int		input_check(int ac, char **av);

//index.c
void	index_stack(t_list **a);

//error.c
void	error_exit(void);
void	error_return(void);

//utils.c
void	free_av(char **av);
void	free_stack(t_list **stack);
int		is_sorted(t_list *stack);

//until_five.c
void	min_to_top(t_list **a);
void	sort_three(t_list **a);
void	simple_sort(t_list **a, t_list **b);

//radix.c
void	radix_sort(t_list **a, t_list **b);

//default movements
void	rotate(t_list **head);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rev_rotate(t_list **head);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	swap(t_list **head);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	push(t_list **src_top, t_list **dst_top);
void	pa(t_list **b, t_list **a);
void	pb(t_list **a, t_list **b);

#endif