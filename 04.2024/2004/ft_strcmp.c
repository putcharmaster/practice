/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:50:40 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/20 19:59:02 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
#include <string.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	printf("%d\n\n", ft_strcmp(av[1], av[2]));
	printf("%d", strcmp(av[1], av[2]));
}
