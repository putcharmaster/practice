/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:03:15 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/18 22:51:47 by sanhwang         ###   ########.fr       */
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
	int	len;
	int	*r;
	int	i;

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










/*
int *ft_range(int start, int end)
{
	int i = 0;
	int len = abs((end - start)) + 1;
	int *res = (int *)malloc(sizeof(int) * len);
	
	while (i < len)
	{
		if (start < end)
		{
			res[i] = start;
			start++;
			i++;
		}
		else
		{
			res[i] = start;
			start--;
			i++;
		}
	}
        return (res);
}


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
	int	*tmp;
	int	len;

	i = 0;
	len = ft_abs(end - start);
	tmp = (int *)malloc(sizeof(int) * len + 1);
	if (!tmp)
		return (NULL);
	while (i <= len)
	{
		if (start < end)
		{
			tmp[i] = start;
			start++;
			i++;
		}
		else
		{
			tmp[i] = start;
			start--;
			i++;
		}
	}
	return (tmp);
}
*/
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

