/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:09:00 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/11 17:24:39 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*read_line(int fd, char *line);
char	*newline(char *line);
char	*restline(char *line);
char	*get_next_line(int fd);
char	*ft_strcpy(char *ret, char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_setzero(char *s, int n);
int		ft_strchr_n(char *s, int c);
int		ft_strlen(char *s);

#endif
