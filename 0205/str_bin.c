/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:21:18 by sanhwang          #+#    #+#             */
/*   Updated: 2024/05/02 17:28:03 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*strtobin(char *s)
{
	if (!s)
		return (NULL);
	int	len;
	len = strlen(s);
	char	*bin;
	bin = malloc(len * 8 + 1);
	if (!bin)
		return (NULL);
	strcpy(bin, ""); //crucial step. without this, the bin string would ontain garbage values
			 // maybe similar to int i, i = 0;step.
			 // "" already contatins a null terminator.
			 // effectively setting the first char of bin to the null char,
			 // ensuring that bin is a valid empty str in C.
	char	*ptr;
	ptr = s;
	int	i;
	while (*ptr)
	{
		i = 7;
		while (i >= 0)
		{
			if (*ptr & 1 << i)
				strcat(bin, "1");
			else
				strcat(bin, "0");
			i--;
		}
		ptr++;
	}
	return (bin);
}

int	main()
{
	char	*s = "hello";
	char	*bin = strtobin(s);
	if (bin)
	{
		printf("%s\n", bin);
		free(bin);
	}
	return (0);
}


struct	sigaction
{
	void	(*sa_handler)(int);
	void	(*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t	sa_mask;
	int		sa_flags;
	void	(*sa_restorer)(void);
}




letter |= (1 << i);
letter = letter | (1 <<7);
