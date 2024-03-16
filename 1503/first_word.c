/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:55:49 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/15 17:38:41 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...    is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/
//my own try
//the word start either position 0 or after tabs(9) or spaces(32).
//and until tabs and space count.
//\n for new line
//if str[0] == 0, return \n;
//use argc argv to get parameter. if parameter is more than 1.  just \n

#include <unistd.h>

void	*new_word(char *str)
{
	int	i;
	int	j;
	char	*new;

	i = 0;
	j = 0;
	while (str[i] == 9 || str[i] == 32)
		i++;
	while (str[i] != 9 && str[i] != 32 && str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		new_word(argv[1]);
	}
	write (1, "\n", 1);
	return (0);
}
