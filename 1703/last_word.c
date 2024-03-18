/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:22:45 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/17 16:52:32 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			i++;
		//i--;  unnecessary line
		while (argv[1][i] <= 32)
			i--;
		while (argv[1][i] > 32)
			i--;
		//i++;
		while (argv[1][i] > 32)
			write(1, &argv[1][i++], 1);
	}
	write(1, "\n", 1);
	return (0);
}




/*
 * nice try    logic was correct but the practice was so poor
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int	len;
	char	*tmp;

	len = ft_strlen(av[1]);
	if (ac == 2)
	{
		while(*av[1][len])
		{
			if(av[1][len] == 32 || 
					(av[1][len] >= 9 && av[1][len] <= 13))
				len--;
			else if(is_alpha(av[1][len]) == 1)
			{
				tmp[len] = av[1][len];
				len--;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/
