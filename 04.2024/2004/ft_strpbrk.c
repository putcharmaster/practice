/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:56:33 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/20 22:03:01 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
				return ((char *)s1);
			i++;
		}
		s1++;
	}
	return (0);
}


#include <string.h>
#include <stdio.h>

int	main()
{
	char *s1;
	char *s2;

	s1 = "abvfsddfg";
	s2 = "xxxxfx";
	printf("%s\n\n",ft_strpbrk(s1, s2));
	printf("%s", strpbrk(s1, s2));

}
