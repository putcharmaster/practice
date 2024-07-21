/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:28:30 by sanhwang          #+#    #+#             */
/*   Updated: 2024/07/21 16:31:32 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	draw_mandelbrot(t_data *data)
{
	int		i;
	int		hue;
	double	tmp;

	i = 0;
	data->z_r = 0.0;
	data->z_i = 0.0;
	data->c_r = (data->pos_x / data->zoom) + data->offset_x;
	data->c_i = (data->pos_y / data->zoom) + data->offset_y;
	while (++i < data->max_iters)
	{
		tmp = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = 2.0 * data->z_r * data->z_i + data->c_i;
		data->z_r = tmp;
		if (data->z_r * data->z_r + data->z_i * data->z_i >= __DBL_MAX__)
			break ;
	}
	if (i == data->max_iters)
		hue = 0x000000;
	else
		hue = (data->color * i);
	put_pixel_to_image(data, data->pos_x, data->pos_y, hue);
}

void	draw_julia(t_data *data)
{
	int		i;
	int		hue;
	double	tmp;

	i = 0;
	data->z_r = (data->pos_x / data->zoom) + data->offset_x;
	data->z_i = (data->pos_y / data->zoom) + data->offset_y;
	while (++i < data->max_iters)
	{
		tmp = data->z_r;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i
			+ data->const_r;
		data->z_i = 2 * data->z_i * tmp + data->const_i;
		if (data->z_r * data->z_r + data->z_i * data->z_i >= __DBL_MAX__)
			break ;
	}
	if (i == data->max_iters)
		hue = 0x000000;
	else
		hue = (data->color * i);
	put_pixel_to_image(data, data->pos_x, SIZE - data->pos_y - 1, hue);
}

void	draw_burningship(t_data *data)
{
	int		i;
	int		hue;
	double	tmp;

	i = 0;
	data->z_r = 0.0;
	data->z_i = 0.0;
	data->c_r = (data->pos_x / data->zoom) + data->offset_x;
	data->c_i = (data->pos_y / data->zoom) + data->offset_y;
	while (++i < data->max_iters)
	{
		tmp = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = fabs(2.0 * data->z_r * data->z_i) + data->c_i;
		data->z_r = fabs(tmp);
		if (data->z_r * data->z_r + data->z_i * data->z_i >= __DBL_MAX__)
			break ;
	}
	if (i == data->max_iters)
		hue = 0x000000;
	else
		hue = (data->color * i);
	put_pixel_to_image(data, data->pos_x, data->pos_y, hue);
}
