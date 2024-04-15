/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 21:07:52 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/15 21:20:34 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int	i;
	char	*dup;

	i = 0;
	if (!src)
		return (NULL);
	while(src[i])
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

#include <stdio.h>
#include <string.h>

int main() {
    char source[] = " ,";
    char *target = ft_strdup(source);
    char *target1 = strdup(source);
    printf("%s\n", target);
    printf("%s", target1);
    free(target);
    return 0;
}

