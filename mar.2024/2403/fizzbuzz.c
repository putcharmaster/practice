/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:30:48 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/24 13:14:58 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putstr(char *str)
{
	while(*str)
		write(1, &*str++, 1);
}

void	putnbr(int n)
{
	char	r;

	if(n < 0)
	{
		write(1, "-", 1);
		n = -n;	
	}
	if (n > 9)
		putnbr(n / 10);
	r = n % 10 + '0';
	write(1, &r, 1);
	
}

void	fizzbuzz(void)
{
	int	n;
	n = 1;
	while(n < 101)
	{
		if (n % 15 == 0)
			putstr("fizzbuzz");
		else if(!(n % 3))
			putstr("fizz");
		else if(!(n % 5))
			putstr("buzz");
		else
			putnbr(n);
		n++;
		write(1, "\n", 1);
	}

}

#include <stdio.h>
int	main(void)
{
	putstr("work");
	write(1,"\n\n", 2);
	putnbr(42);
	write(1,"\n\n", 2);
	fizzbuzz();


}
