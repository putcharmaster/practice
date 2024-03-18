/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:05:55 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/17 19:18:28 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check(int c, char *str, int index)
{
	int i = 0;
	
	while(i < index)
	{
		if (str[i] == c)
			return 0;
		i++;
	}
	return  1;
}

int main(int argc, char **argv)
{	
	int i = 0;
	int j = 0;
	int k = 0;
	
	if (argc == 3)
	{
		while(argv[1][i] != '\0')
		{
			i++;
		}
		while(argv[2][j] != '\0')
		{
			argv[1][i] = argv[2][j];
			i++;
			j++;
		}
		i--;
		while(k <= i)
		{
			if(check(argv[1][k], argv[1], k) == 1) 
				write (1, &argv[1][k], 1); 
			k++;
		}
	}
	write (1, "\n", 1);
}

#include <string.h> // Include for strcat

void ft_union(char *s1, char *s2)
{
    char str[256] = {0}; // Initialize str with zeros

    // Concatenate s1 and s2 into str
    strcat(str, s1);
    strcat(str, s2);
}


