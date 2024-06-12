/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:40:30 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/11 22:13:33 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void    move(t_stack **a, t_stack **b);
int	 max(int a, int b);
int	 min(int a, int b);
int	calculate_cost(int index_a, int index_b, int size_a, int size_b);
int	find_cheapest_move(t_stack *a, t_stack *b, int *index_a, int *index_b);
void execute_cheapest_move(t_stack **a, t_stack **b);
int     find_index(t_stack *stack, int value);
int	last_stack_value(t_stack *stack);

void    do_a_pb(t_stack **a, t_stack **b);
void    place_smallest_in_a_on_top(t_stack **a);

void    move_to_top(t_stack **stack, int index, char stack_id);
void    move_to_top_b(t_stack **stack, int index);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	**ft_split(const char *s, char c);
int		print_error(void);
void	make_stack(char **av, t_stack **a_head);
void	add_n_to_back(t_stack **a_head, int value);
void	free_av(char **av);
void	algo(t_stack **a, t_stack **b);
void	free_stack(t_stack *head);
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rotate(t_stack **head);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rev_rotate(t_stack **head);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	push(t_stack **src_top, t_stack **dst_top);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	make_three_and_sort(t_stack **a, t_stack **b, int max, int min);
void	sort_three(t_stack **a, int max, int min);
void	sort_four(t_stack **a, t_stack **b, int max, int min);
int	int_range(char **av);
int	is_dup(t_stack *a);
int	is_sorted(t_stack *a);
int	is_digit(char c);
int	is_sign(char c);
int	valid_input(int ac, char **av);
long	ft_atol(char *str);
int		ft_atoi(char *str);
int	out_of_int(char **split);
int	ft_lstsize(t_stack *a_head);
int	stack_size(t_stack *head); // do i need this?
int	find_min_value(t_stack *stack);
int	find_max_value(t_stack *stack);
int	find_mean_value(t_stack *stack);
int	find_mean(t_stack **head); // do i need this?


#endif
