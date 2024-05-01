/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:46:08 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/27 13:06:37 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	start;
	int	end;
	char	*str;

	str = av[1];
	i = 0;
	start = 0;
	end = 0;
	if (ac > 1)
	{
		while (str[i] < 33)
			i++;
		start = i;
		while (str[i] > 32)
			i++;
		end = i;
		while (str[i] && str[i] < 33)
			i++;
		if (str[i])
		{
			while (str[i])
			{
				if (str[i] < 33)
				{
					while (str[i] < 33)
						i++;
					write(1, " ", 1);
				}
				write(1, &str[i++], 1);
			}
			write(1, " ", 1);
		}
		while (start < end)
			write(1, &str[start++], 1);

	}
	write(1, "\n", 1);
	return (0);
}
