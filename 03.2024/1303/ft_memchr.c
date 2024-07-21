/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:30:35 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/13 14:44:02 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// do it again later
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
}

/*  1st try,  wrong but not sooo far from the correct one.  
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	f;
	size_t	i:

	i = 0;
	str = s;
	f = (unsigned char)c;
	if (!s && !c)
		return (NULL);
	while (str[i] < n && str && f)
	{
		if(str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
*/
