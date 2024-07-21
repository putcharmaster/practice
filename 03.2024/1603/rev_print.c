/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:38:46 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/16 13:59:58 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if(ac == 2)
	{
		while(av[1][i])
			i++;
		while(i)
			write(1, &av[1][i--], 1);
	}
	write(1, "\n", 1);
	return (0);
}

///////////////////
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	*ft_putstr(char *str)
{
	while(*str)
	{
		write(1, str, 1);
		str++;
	}
}

char	*revers(char *str)
{
	char	*tmp;
	int	i;
	int	j;

	tmp = malloc(strlen(str) + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while(str[i])
		i++;
	while(i > 0)
	{
		tmp[j] = str[i - 1];
		j++;
		i--;
	}
	tmp[j] = 0;
	ft_putstr(tmp);
	free(tmp);
	return tmp;
}

int	main(int ac, char **av)
{
	if(ac == 2)
	{
		revers(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
