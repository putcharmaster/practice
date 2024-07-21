/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:10:20 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/30 15:09:03 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>

size_t	ui_len(unsigned int n);
size_t	n_len(int n);
size_t	h_len(unsigned long long n);
void	r_int(int n);
void	ptr_hexa(unsigned long long ptr);
int		ft_str(char *str);
int		ft_char(int c);
int		ft_ui(unsigned int n);
int		ft_int(int n);
int		ft_hexa(unsigned long long n, const char Xx);
int		ft_void(void *ptr);
int		check_spec(const char s, va_list ap);
int		ft_printf(const char *str, ...);

#endif
