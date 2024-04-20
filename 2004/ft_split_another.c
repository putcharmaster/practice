/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_another.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:13:27 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/20 14:20:08 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


so damn hard.....................................
////////////////////////////////////////////////
int	word_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < ft_strlen(str) - 1)
}

char	**ft_split(char *str)
{
	char	**tab;

	tab = malloc(sizeof(char *) * word_count(str) + 1);
	if (!str || !tab)
		return (NULL);
	tab = fill(tab, str);
	return (tab);

}
