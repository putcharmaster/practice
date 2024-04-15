/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:07:16 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/15 16:20:27 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_n(char c, int i)
{
	while (i--)
		write(1, &c, 1);
}

void	repeat_alpha(char *c)
{
	while (*c)
	{
		if (*c >= 'a' && *c <= 'z')
			ft_putchar_n(*c, *c + 1 - 'a');
		else if (*c >= 'A' && *c <= 'Z')
			ft_putchar_n(*c, *c + 1 - 'A');
		else
			write(1, c, 1);
		c++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		repeat_alpha(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
