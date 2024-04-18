/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:16:35 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/18 16:36:00 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s2[i] = '\0';
	return (s1);
}

int	main()
{
	char	s1[100];
	char	s2[] = "abcdefghijklmnop";

	ft_strcpy(s1, s2);
	printf("%s\n\n%s", s1, s2);

}
