/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:53:41 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/27 15:03:47 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

void	fill(char **tab, t_point size, t_point begin, char tofill)
{
	if (begin.y < 0 || begin.x < 0 || begin.y >= size.y || begin.x >= size.x
		|| tab[begin.y][begin.x] != tofill)
		return;
	tab[begin.y][begin.x] = 'F';
	fill(tab, size, (t_point){begin.x - 1, begin.y}, tofill);
	fill(tab, size, (t_point){begin.x + 1, begin.y}, tofill);
	fill(tab, size, (t_point){begin.x, begin.y - 1}, tofill);
	fill(tab, size, (t_point){begin.x, begin.y + 1}, tofill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
