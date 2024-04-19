/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:03:46 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/19 13:08:15 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

int	*ft_rrange(int start, int end)
{
	int	i;
	int	len;
	int	*r;

	i = 0;
	len = ft_abs(start - end) + 1;
	r = malloc(sizeof(int) * len);
	if (!r)
		return (NULL);
	while (i < len)
	{
		r[i] = end;
		if (start < end)
			end--;
		else
			end++;
		i++;
	}
	return (r);
}

#include <stdio.h>

int main()
{
    int start = -5;
    int end = 10;
    int *rrange = ft_rrange(start, end);
    if (rrange == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Assuming the end value is included in the array
    for (int i = 0; i < ft_abs(start - end) + 1; i++)
    {
        printf("%d ", rrange[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(rrange);

    return 0;
}

