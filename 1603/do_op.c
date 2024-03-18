/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 20:48:13 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/16 20:53:35 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if(ac == 4)
	{
		if(av[2][0] == '+')
			printf("%d", (atoi(av[1]) + atoi(av[3])));
		if(av[2][0] == '-')
			printf("%d", (atoi(av[1]) - atoi(av[3])));
		if(av[2][0] == '*')
			printf("%d", (atoi(av[1]) * atoi(av[3])));
		if(av[2][0] == '/')
			printf("%d", (atoi(av[1]) / atoi(av[3])));
		if(av[2][0] == '%')
			printf("%d", (atoi(av[1]) % atoi(av[3])));
	}
	printf("\n");
	return (0);
}


/*
 * int ft_do_op(int a, int b, char c)
{
	if (c == '*')
		return (a * b);
	else if (c == '+')
		return (a + b);
	else if (c == '-')
		return (a - b);
	else if (c == '/')
		return (a / b);
	else if (c == '%')
		return (a % b);
	return (0);
}


int main (int ac, char **av)
{
	if(ac == 4)
	{
		printf("%d\n", ft_do_op(atoi(av[1]), atoi(av[3]), av[2][0]));
	}
	else
		write(1, "\n", 1);
	return (0);
}
*/
