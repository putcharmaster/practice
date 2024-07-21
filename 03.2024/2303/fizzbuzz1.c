/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:40:55 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/23 13:09:34 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_nbr(int n)
{
	char	*str;

	str = "0123456789";
	if (n > 9)
		write_nbr(n / 10);
	write (1, &str[n%10], 1);
}

void	putstr(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main()
{
	int	i;

	i = 1;
	while(i < 101)
	{
		if (i % 15 == 0)
			putstr("fizzbuzz");
		else if(i % 3 == 0)
			putstr("fizz");
		else if(i % 5 == 0)
			putstr("buzz");
		else
			write_nbr(i);
		i++;
		write(1, "\n", 1);
	}
}
