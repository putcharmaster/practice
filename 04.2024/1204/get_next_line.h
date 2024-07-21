/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:56:51 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/13 15:20:12 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 400
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *ret, char *s1, char *s2);
char	*leftover(char *line);
char	*newline(char *line);
char	*read_line(int fd, char *line);
int		ft_strlen(char *s);
int		ft_strchr_n(char *s, int c);
void	*ft_setzero(char *s, int n);

#endif
