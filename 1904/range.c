/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:32:25 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/19 08:36:48 by sanhwang         ###   ########.fr       */
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
	int	*r;
	int	i;
	int	len;

	len = ft_abs(start - end) + 1;
	i = 0;
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
    int start = -5;
    int end = 5;
    int *range = ft_range(start, end);
    if (range == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Assuming the end value is included in the array
    for (int i = 0; range[i] != end; i++)
    {
        printf("%d ", range[i]);
    }
    printf("%d\n", end); // Print the end value separately

    // Free the allocated memory
    free(range);

    return 0;
}

