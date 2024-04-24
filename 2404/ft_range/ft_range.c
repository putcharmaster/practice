/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:53:32 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/24 18:12:58 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	*ft_range(int start, int end)
{
	int	len;
	int	*r;
	int	i;

	i = 0;
	len = ft_abs(start - end);
	r = malloc(sizeof(int) * (len + 1));
	if (!r)
		return (NULL);
	while (i <= len)
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
/*
#include <stdio.h>
int	main()
{
	int start = 40;
	int end = -6;
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
*/
