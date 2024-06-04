/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:40:30 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/28 19:18:59 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	split_av(char **av, t_stack **a_head);
void	add_n_to_back(t_stack **a_head, int value);
void	free_av(char **av);
void	algo(t_stack **a, t_stack **b);
void	free_stack(t_stack *head);
int	is_sorted(t_stack *a);
int	is_digit(char c);
int	valid_input(int ac, char **av);
int	ft_atol(char *str);
int	out_of_int(long n);
int	ft_lstsize(t_stack *a_head);

#endif
