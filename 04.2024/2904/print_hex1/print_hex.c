/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:02:37 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/29 21:12:37 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	r;
	i = 0;
	r = 0;
	while (str[i])
	{
		r = r * 10 + str[i++] - '0';
	}
	return (r);
}

void	puthex(int n)
{
	char *r;
	r = "0123456789abcdef";

	if (n > 16)
		puthex(n / 16);
	write(1, &r[n % 16], 1);
}
	
int	main(int ac, char **av)
{
	int	n;
	if (ac == 2)
	{
		n = ft_atoi(av[1]);
		puthex(n);
	}
	write(1, "\n", 1);
	return (0);
}
