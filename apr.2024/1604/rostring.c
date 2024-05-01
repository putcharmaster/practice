/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 23:39:32 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/16 23:42:21 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_word(char *start, char *end)
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
