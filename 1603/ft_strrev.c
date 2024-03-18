/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 21:51:45 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/16 22:00:40 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int	i;
	int	len;
	char	temp;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while(i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
	return (str);
}

#include <stdio.h>

int	main()
{
	char str[] = "revab";
printf("%s", ft_strrev(str));
}


/*
 *
#include <stdlib.h>
#include <string.h>

int main() {
    char *str = strdup("rev"); // Creates a modifiable copy of the string literal
    if (str) {
        printf("%s", ft_strrev(str));
        free(str); // Don't forget to free the allocated memory
    }
    return 0;
}

 */
