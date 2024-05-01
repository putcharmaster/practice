/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:21:12 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 14:41:20 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
int	 main(int argc, char const *argv[])
{
	int i;
	int flg;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ' || argv[1][i] == '\t')
				flg = 1;
			if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
			{
				if (flg)
					write(1, " ", 1);
				flg = 0;
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/
int     main(int ac, char **av)
{
        int     i;
        int     flg;

        if (ac == 2)
        {
                i = 0;
                while (av[1][i] == ' ' || av[1][i] == '\t')
                        i++;
                while (av[1][i])
                {
                        if (av[1][i] == ' ' || av[1][i] == '\t')
                                flg = 1;
			else
			{
                                if (flg)
                                        write(1, " ", 1);
                                flg = 0;
                                write(1, &av[1][i], 1);
                        }
                        i++;
                }
        }
        write(1, "\n", 1);
        return (0);
}

/*
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	epur_str(char *str)
{
	char	sp;
	int	i;

	sp = -1;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (sp == 1)
				ft_putchar(' ');
			sp = 0;
			ft_putchar(str[i]);
		}
		else if (sp == 0)
			sp = 1;
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	ft_putchar('\n');
	return (0);
}

*/
/*
int	main(int ac, char **av)
{
	int	i;
	int	flg;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i] = ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			if (av[1][i] = ' ' || av[1][i] == '\t')
				flg = 1;
			if (!(av[1][i] = ' ' || av[1][i] == '\t'))
			{
				if (flg)
					write(1, " ", 1);
				flg = 0;
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
*/
