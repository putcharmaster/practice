/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:23:20 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/17 19:23:25 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_wdmatch(char *a, char *b)
{
	int j = 0; // counter for second string
	int i = 0; // counter for first string

	while ((a[i] && b[j]) != 0)
	{
		if (a[i] == b[j]) // if char in both the strings are same then proceed further
		{
			i++;
			j++;
			if (a[i] == '\0') // check if we reached the end point of first string
			{
				while (*a) // print the whole string
				{
					write (1, a, 1);
					a++;
				}
				return ;
			}
		}
		else
			j++;
	}
}

int main (int ac, char **av) // main driver function
{
	if (ac == 3)
	{
		ft_wdmatch(av[1], av[2]);
	}
	write (1, "\n", 1);
	return (0);
}
