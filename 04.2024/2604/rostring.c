/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:21:27 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/27 12:45:44 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
/*
void write_word(char *start, char *end)
{
    while (start < end)
    {
        write(1, start, 1);
        start++;
    }
}

int main(int argc, char **argv)
{
    char *str;
    char *first_word_start;
    char *first_word_end;

    if (argc > 1)
    {
        str = argv[1];
        while (*str == ' ' || *str == '\t') 
            str++;
        first_word_start = str;
        while (*str && *str != ' ' && *str != '\t')
            str++;
        first_word_end = str;
        while (*str == ' ' || *str == '\t')
            str++;
        if (*str) {
            while (*str)
            {
                if (*str == ' ' || *str == '\t')
                {
                    while (*str == ' ' || *str == '\t')
                        str++;
                    if (*str)
                        write(1, " ", 1);
                } 
                else 
                {
                    write(1, str, 1);
                    str++;
                }
            }
            write(1, " ", 1);
        }
        write_word(first_word_start, first_word_end);
    }
    write(1, "\n", 1);
    return 0;
}
*/
/*
#include <unistd.h>

void	word(char *str, int s, int e)
{
	while (s < e)
		write(1, &str[s++], 1);
}

int	main(int ac, char **av)
{
	int	i;
	int	s;
	int	e;
	
	i = 0;
	s = 0;
	e = 0;
	if (ac >= 2)
	{
		while (av[1][i] < 33)
			i++;
		s = i;
		while (av[1][i] > 32)
			i++;
		e = i;
		while (av[1][i] < 33)
			i++;
		if (av[1][i])
		{
			while(av[1][i])
			{
				if (av[1][i] < 33)
			{
					while (av[1][i] < 33)
						i++;
					write(1, " ", 1);
				}
				write(1, &av[1][i], 1);
				i++;
			}
		}
		write(1, " ", 1);
		word(av[1], s, e);
	}
	write(1, "\n", 1);
	return (0);
}
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	start;
	int	end;

	if (ac >= 2)
	{
		i = 0;
		start = 0;
		end = 0;
		while (av[1][i] && av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		start = i;
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			i++;
		end = i;
		if (av[1][i])
		{
			while (av[1][i] && av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			while (av[1][i])
			{
				if (av[1][i] && av[1][i] == ' ' || av[1][i] == '\t')
				{
					while (av[1][i] == ' ' || av[1][i] == '\t')
						i++;
					write(1, " ", 1);
		
￼
		}
				write(1, &av[1][i++], 1);
			}
		}
		write(1, " ", 1);
		while (start < end)
			write(1, &av[1][start++], 1);

	}
	write(1, "\n", 1);
	return (0);
}

