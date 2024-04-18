/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:38:53 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/18 16:59:26 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar_n(char c, int n)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}

void	repeat_alpha(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			putchar_n(str[i], str[i] - 'a' + 1);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			putchar_n(str[i], str[i] - 'A' + 1);
		else
			write(1, &str[i], 1);
		i++;
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
