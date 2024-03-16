/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:35:17 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/16 14:47:40 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	rotone(char c)
{
	if((c >= 'A' && c <= 'Y') || (c >= 'a' && c <= 'y'))
		c = c + 1;
	else if(c == 'Z' || c == 'z')
		c = c - 25;
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		while(*av[1])
		{
			ft_putchar(rotone(*av[1]++));
		}
	}
	write(1, "\n", 1);
	return (0);
}
