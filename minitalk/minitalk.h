/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:46:35 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/13 12:51:22 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

void	simple_putnbr(int n);
void	sig_handler(int signal, siginfo_t *info, void *context);
void	ft_ctob(int pid, char c);
int		simple_atoi(char *str);

#endif
