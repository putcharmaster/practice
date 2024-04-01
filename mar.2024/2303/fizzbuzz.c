/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:03:47 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/23 12:40:31 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
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
	while(i < 101)
	{
		     c = i % 10 + '0';
        d = i / 10 + '0';

		if(i % 3 == 0 && i % 5 == 0)
			ft_putstr("fizzbuzz");
		else if(i % 3 == 0)
			ft_putstr("fizz");
		else if(i % 5 == 0)
			ft_putstr("buzz");
		else
		{	
			if(i < 10)
				write(1, &c, 1);
			if(i ==  100)
				write(1,"buzz",4);	
			else if(i > 9 && i < 100)
			{
				write(1, &d, 1);
				write(1, &c, 1);
			}
		}
		i++;
		write(1, "\n", 1);	
	}
}

int	main()
{
	fizzbuzz();
}
