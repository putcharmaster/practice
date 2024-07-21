/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:03:35 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/19 20:19:37 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(int n)
{
	char	*r;

	r = "0123456789abcdef";
	if (n > 16)
		print_hex(n / 16);
	write(1, &r[n % 16], 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
		r = r * 10 + str[i++] - '0';
	return (r);
}

int main(int ac, char **av)
{
	int	nr;

	if (ac == 2)
	{
		nr = ft_atoi(av[1]);
		print_hex(nr);
	}
	write(1, "\n", 1);
	return (0);
}
