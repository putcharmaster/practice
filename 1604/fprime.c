/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 22:19:12 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 22:41:03 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	n;
	int	nb;

	if (ac == 2)
	{
		if (av[1][0] == '\0')
		{
			printf("\n");
			return(0);
		}
		nb = atoi(av[1]);
		if(nb == 1)
		{
			printf("1\n");
			return(0);
		}
		while(1)
		{
			n = 1;
			while (++n <= nb)
			{
				if(nb % n == 0)
				{
					printf("%d", n);
					nb = nb / n;
					break ;
				}
			}
			if (nb == 1)
				break ;
			else
				printf("*");
		}
	}
	printf("\n");
	return (0);
}


////////////////////////////////////////////////////////

void	ft_fprime(char *str)
{
	int	n;
	int	div;

	div = 2;
	n = atoi(str);
	if(n == 1)
		printf("1");
	if (n <= 1)
		return ;
	while (div <= n)
	{
		if(n % div == 0)
		{
			printf("%d", div);
			if (n == div)
				return ;
			printf("*");
			n = n / div;
			div = 1;
		}
		div++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_fprime(av[1]);
	printf("\n");
	return (0);
}





////////////////////////////////////////////////////////

int	main(int ac, char **av)
{
	int	i;
	int	n;

	if (ac == 2)
	{
		i = 1;
		n = atoi(av[1]);
		if (n == 1)
			printf("1");
		while (n >= ++i)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				if (n == i)
					break ;
				print("*");
				n /= i;
				i = 1;
			}
		}
	}
	printf£("\n");
	return (0);
}
