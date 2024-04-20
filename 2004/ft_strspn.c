/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:38:22 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/20 21:40:16 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (!(ft_strchr(accept, s[i])))
			break ;
		i++;
	}
	return (i);
}

/*
#include <string.h>

size_t ft_strspn(const char *str, const char *chars) {
    int i;
    char ch[256] = {0}; // Create a lookup table for ASCII characters

    // Populate the lookup table with the characters from chars
    for (i = 0; i < strlen(chars); i++) {
        ch[chars[i]] = 1;
    }

    // Check each character in str against the lookup table
    for (i = 0; i < strlen(str); i++) {
        if (ch[str[i]] == 0) { // If the character is not in chars, break the loop
            break;
        }
    }

    return i; // Return the number of characters at the beginning of str that are in chars
}
*/
/*
//  result is not the same as strspn
size_t	ft_strspn(const char *s, const char *accept)
{
	const char	*s1;
	const char	*s2;

	s1 = s;
	s2 = accept;
	while (*s1)
	{
		while (1)
		{
			if (*s1 == *s2)
				break ;
			else if (*s2++ == 0)
				return (s1 - s);
		}
		s1++;
	}
	return (s1 - s);
}
*/
#include <stdio.h>
#include <string.h>
int     main()
{
        char *s1;
        char    *s2;

        s1 = "bccdefg";
        s2 = "bcdcegfk";
        printf("%ld\n\n", ft_strspn(s1, s2));
        printf("%ld", strspn(s1, s2));
}
    
