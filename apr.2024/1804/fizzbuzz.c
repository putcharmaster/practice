/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:42:15 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/18 16:11:29 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_nr(int	n)
{
	char	*str;

	str = "0123456789";
	if (n > 9)
		ft_write_nr(n / 10);
	write(1, &str[n % 10], 1);
}

int	main()
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_write_nr(i);
		i++;
		write(1, "\n", 1);
	}
}

/////////////////////////////////////////////////////////////////////////
/*
void	ft_itoa(int n)
{
	int	len;
	char	*s;
	
	len = 0;
	while(n)
		len++;
	while(n[len])
		
}

void	putchar(char *str)

void	fizzbuzz()
{
	int	i;
	char	c;
	char	d;

	i = 1;
	c = 0;
	d = 0;
	while (i < 100)
	{
		if (!(i % 15) || !(i % 3) || !(i % 5))
		{}
		else
		{
			c = i % 10 + '0';
			d = i / 10 + '0';
		}
	}
}

int	main()
{

}
*/
