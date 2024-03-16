/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:00:45 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/16 14:29:18 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	rot_13(char c)
{
	if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
		c = c + 13;
	else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
		c = c - 13;
	return (c);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		while (*av[1])
			ft_putchar(rot_13(*av[1]++));
	}
	ft_putchar('\n');
	return (0);
}


/*

//////////////so wrong :(
#include <unistd.h>

void	*new_chr(char c)
{
	char	b;

	b = c - 13;
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		if(c)
			write(1, &b, 1);
	}
	else
		write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		new_chr(av[1][i]);
	}
	write(1, "\n", 1);
	return (0);
}
*/
