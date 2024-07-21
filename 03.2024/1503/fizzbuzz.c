/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:42:52 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/23 12:34:19 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead

*/

//major problem from 10. because write (1, &c, 1) only writes one 
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	fizzbuzz(void)
{
	int	i;
	char	c;
	char	d;

	i = 1;
	while (i < 101)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write (1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write (1, "buzz", 4);
		else
		{
			c = i % 10 + '0';
			d = i / 10 + '0';
			if (i < 10)
				write (1, &c, 1);
			if (i == 100)
				write (1, "buzz", 4);
			else if (i > 9 && i < 100)
			{
				write (1, &d, 1);
				write (1, &c, 1);
			}
		}
		i++;
		write (1, "\n", 1);
	}
}

int	main(void)
{
	fizzbuzz();
	ft_putstr("working?");
	return (0);
}
