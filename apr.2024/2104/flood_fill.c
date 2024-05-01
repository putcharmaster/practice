/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:32:13 by sanhwang          #+#    #+#             */
/*   Updated: 2024/04/21 16:38:45 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.x < 0 || cur.y < 0 || cur.x >= size.x || cur.y >= size.y || tab[cur.y][cur.x] != to_fill)
		return;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);  
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);  
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);  
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);  
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, tab[begin.y][begin.x]);
}
