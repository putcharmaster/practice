/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:11:16 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/17 15:22:16 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_atoi(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while(str[i] >= '0' && str[i] <= '9')
		r = r * 10 + str[i++] - '0';
	return (r);
}

void	print_hex(unsigned int n)
{
	char	*digit;
	digit = "0123456789abcdef";

	if (n > 9)
		print_hex(n / 16);
	write(1, &digit[n % 16], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		print_hex(ft_atoi(av[1]));
	}
	write(1, "\n", 1);
	return (0);
}
