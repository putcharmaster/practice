/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:04:48 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/27 21:31:51 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	capi(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= 'A' && str[i] <= 'Z')
		write(1, &str[i++], 1);
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		if ((str[i] >= 'a' && str[i] <= 'z')
			&& (i == 0 || str[i - 1] == ' ' || str[i - 1] == '\t'))
			str[i] = str[i] - 32;
		write(1, &str[i++], 1);
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			capi(av[i]);
			if (i < ac - 1)
				write(1, "\n", 1);
			i++;
		}
	}
		write(1, "\n", 1);
	return (0);
}
