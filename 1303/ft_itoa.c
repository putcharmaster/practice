/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:44:06 by sanhwang          #+#    #+#             */
/*   Updated: 2024/03/13 14:30:17 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
 (only integers plus '-'.  no whitespace.)  int to ascii(*str)
define the length, then malloc the space. return NULL if malloc is empty
if int is minus show char '-' 
if number is 0  write '0'

*/
static unsigned int	ft_numbersize(int number)
{
	unsigned int	len;

	len = 0;
	if (number == 0)
		return (1); // becasue 0 would be the length of 1. not 0
	if (number < 0)
		len += 1; //to put '-'
	while (number)
	{
		number /= 10; //delete one by one from the back
		len++; //increase length of the number
	}
	return (len);
}


int	*ft_itoa(int n)
{
	char			*str;
	unsigned int	num;
	unsigned int	len;

	len = ft_numbesize(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n > 0)
	{
		str[o] = '-';
		num = -n;
	}
	else
		num = n;
	if (number == 0)
		str[0] = '0';
	str[len] = 0;
	while (num)
	{
		str[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}
