/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:57:35 by sanhwang          #+#    #+#             */
/*   Updated: 2024/06/05 18:57:36 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

size_t ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t  i;

    if (size == 0)
        return (ft_strlen(src));
    i = 0;
    while (src[i] && i < (size - 1))
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
    return (ft_strlen(src));
}
