/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:30:38 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/08 19:56:07 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	new = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, s1len + 1);
	ft_strlcat(new, s2, s1len + s2len + 1);
	return (new);
}
