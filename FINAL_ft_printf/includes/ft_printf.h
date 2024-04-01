/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:10:20 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/01 20:44:25 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

size_t	ui_len(unsigned int n);
size_t	n_len(int n);
size_t	h_len(unsigned int n);
size_t	p_len(uintptr_t n);
void	recursive_int(int n);
void	recursive_hexa(uintptr_t ptr);
int		ft_str(char *s);
int		ft_char(int c);
int		ft_ui(unsigned int n);
int		ft_int(int n);
int		ft_hexa(unsigned int n, const char Xx);
int		ft_void(void *ptr);
int		check_spec(const char s, va_list ap);
int		ft_printf(const char *str, ...);

#endif
