/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:26:58 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/16 13:38:10 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

void	ft_putchar_n(char c, int i)
{
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

void	repeat_alpha(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			ft_putchar_n(*str, *str + 1 - 'A');
		else if (*str >= 'a' && *str <= 'z')
			ft_putchar_n(*str, *str + 1 - 'a');
		else
			write(1, str, 1);
		str++;

	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		repeat_alpha(av[1]);

	write(1, "\n", 1);
	return (0);
}
