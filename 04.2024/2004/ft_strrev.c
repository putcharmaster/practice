/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:04:58 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/20 22:16:22 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	tmp;
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
	return (str);
}

#include <stdio.h>
int	main(int ac, char **av)
{

	
	printf("%s", ft_strrev(av[1]));
}
