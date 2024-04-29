/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:05:46 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/27 22:17:49 by sanhwang         ###   ########.fr       */
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

	s = "abcdeiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiif";
	r = "x1356iiiiiiiiiiiiiiiibiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiibx";
	printf("original ; %ld\n\n", strcspn(s, r));
	printf("ft_ ; %ld", ft_strcspn(s, r));
}
*/
