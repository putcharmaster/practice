/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:42:12 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/16 21:50:29 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	while(*s1)
	{
		while(*s2)
		{
			if (*s1 == *s2)
				return (s1);
			s2++;
		}
		s1++;
	}
	return (0);
}