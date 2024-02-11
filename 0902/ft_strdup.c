/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:40:47 by sanhwang          #+#    #+#             */
/*   Updated: 2024/02/09 14:02:23 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *str)
{
	char	*dup;

	dup = (char *)malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	dup = ft_strdup(dup, str);
	return (dup);
}
*/
/////////////////////

#include <stdlib.h>

/*
	count,
	malloc,
	copy.
	return the copy
*/

char	*ft_strdup(char	*str)
{
	int	i;
	char	*dup;

	i = 0;
	while (str[i])
		i++;
	dup = (char *)malloc(i + 1);
	if (!dup)
		return NULL;
	while (i--)
		dup[i] = str[i];
	return (dup);
}

#include <stdio.h>
int	main()
{
	printf("%s", ft_strdup("test"));
}
