/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:11:54 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 13:16:59 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (reject[j])
		{
			if (s[i] == reject[j])
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
	const char *s;
	const char *r;

	s = "skfjv";
	r = "zzzzzzzzzzzzzzzzzzzzzzzzkz";
	printf("original %ld\n\n",strcspn(s, r));
	printf("ft_ %ld", ft_strcspn(s,r));
}
*/
