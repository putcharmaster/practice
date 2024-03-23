/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:28:28 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/23 13:38:08 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_n(char c, int i)
{
	while(i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

void	repeat_alpha(char *str)
{
	while(*str)
	{
		if(*str >= 'a' && *str <= 'z')
			ft_putchar_n(*str, *str - 'a' + 1);
		else if(*str >= 'A' && *str <= 'Z')
			ft_putchar_n(*str, *str - 'A' + 1);
		else
			write(1, str, 1);
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		repeat_alpha(av[1]);
	}
	write(1, "\n", 1);
	return(0);
}
