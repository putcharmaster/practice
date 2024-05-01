/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 21:25:06 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/28 21:56:46 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rostring(char *str)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = 0;
	        while (str[i] == ' ' || str[i] == '\t')
                        i++;
                start = i;
                while (str[i] && str[i] != ' ' && str[i] != '\t')
                        i++;
                end = i;
                while (str[i] == ' ' || str[i] == '\t')
                        i++;
                if (str[i])
                {
                        while (str[i])
                        {
                                if (str[i] == ' ' || str[i] == '\t')
                                {
                                        while (str[i] == ' ' || str[i] == '\t')
                                                i++;
					if (str[i])
						write(1, " ", 1);
                                }
				else
                                	write(1, &str[i++], 1);
                        }
                        write(1, " ", 1);
                }
                while (start < end)
                        write(1, &str[start++], 1);


}

int	main(int ac, char **av)
{
	char	*str;

	if (ac > 1)
	{
		str = av[1];
		rostring(str);
	
	}
	write(1, "\n", 1);
	return (0);
}
