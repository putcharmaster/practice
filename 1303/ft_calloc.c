/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:24:37 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/13 13:43:45 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*t;

	t = (unsigned char *)s;
	while (n--)
		*t++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count & size && count > (SIZE_MAX / size))
		return (NULL);
	ptr = malloc(count * size)
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
