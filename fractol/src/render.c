#include "../inc/fractol.h"

void    apply_zoom(t_data *data, int x, int y, int direction)
{
    double  zoom_factor;

    zoom_factor = 1.20;
    data->offset_x = (x / data->zoom + data->offset_x)
        - (x / (data->zoom * zoom_factor));
    data->offset_y = (x / data->zoom + data->offset_y)
        - (y / (data->zoom * zoom_factor));
    if (direction == 1)
        data->zoom *= zoom_factor;
    else if (direction == -1)
        data->zoom /= zoom_factor;
}

void rendering(t_data *data)
{
    data->pos_x = 0;
    data->pos_y = 0;
    while (data->pos_x < SIZE)
    {
        while (data->pos_y < SIZE)
        {
            if (!strcmp(data->type, "julia"))
                draw_julia(data);
            else if (!strcmp(data->type, "mandelbrot"))
                draw_mandelbrot(data);
            else if (!strcmp(data->type, "burningship"))
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