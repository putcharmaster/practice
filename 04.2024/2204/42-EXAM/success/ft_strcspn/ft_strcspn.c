/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:30:30 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/22 18:37:18 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (reject[j])
		{
			if (reject[j] == s[i])
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	return (i);
}
/*

#include <string.h>
#include <stdio.h>
int	main()
{
	char *s1;
	char *s2;

	s1 = "abcde";
	s2 = "zzzzzzza";
	printf("%ld\n\n",  strcspn(s1, s2));
	printf("%ld", ft_strcspn(s1, s2));
}
*/
