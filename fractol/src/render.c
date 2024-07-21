/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanhwang <sanhwang@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:28:49 by sanhwang          #+#    #+#             */
/*   Updated: 2024/07/21 16:28:51 by sanhwang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void apply_zoom(t_data *data, int x, int y, int direction)
{
    double zoom_factor = 1.50;

    if (direction == -1)
        zoom_factor = 1.0 / zoom_factor;

    double new_zoom = data->zoom * zoom_factor;
    data->offset_x = (x / data->zoom + data->offset_x) - (x / new_zoom);
    data->offset_y = (y / data->zoom + data->offset_y) - (y / new_zoom);
    data->zoom = new_zoom;
}

void rendering(t_data *data)
{
    data->pos_x = 0;
    data->pos_y = 0;
    while (data->pos_x < SIZE)
    {
        while (data->pos_y < SIZE)
        {
            if (!ft_strcmp(data->type, "julia"))
                draw_julia(data);
            else if (!ft_strcmp(data->type, "mandelbrot"))
                draw_mandelbrot(data);
            else if (!ft_strcmp(data->type, "burningship"))
                draw_burningship(data);
            data->pos_y++;
        }
        data->pos_x++;
        data->pos_y = 0;
    }
}

void    render_fractal(t_data *data)
{
    if (!ft_strcmp(data->type, "julia") 
        && (!data->const_r && !data->const_i))
    {
        data->const_r = -0.745429;
        data->const_i = 0.05;
    }
    rendering(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
