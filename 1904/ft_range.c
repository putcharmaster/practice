/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:52:11 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/19 13:05:28 by sanhwang         ###   ########.fr       */
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

int	*ft_range(int start, int end)
{
	int	i;
	int	*r;
	int	len;

	i = 0;
	len = ft_abs(start - end) + 1;
	r = malloc(sizeof(int) * len);
	if (!r)
		return (NULL);
	while (i < len)
	{
		r[i] = start;
		if (start < end)
			start++;
		else
			start--;
		i++;
	}
	return (r);
}

#include <stdio.h>

int main()
{
    int start = 50;
    int end = -1;
    int *range = ft_range(start, end);
    if (range == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Assuming the end value is included in the array
    for (int i = 0; i < ft_abs(start - end) + 1; i++)
    {
        printf("%d ", range[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(range);

    return 0;
}

