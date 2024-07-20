#include "../inc/fractol.h"

int     exit_program(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img);
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    free(data->type);
    free(data);
    exit(0);
    return (0);
}

void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->line_size + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
static void    iterate(t_data *data, int key_code)
{
    if (key_code == P_KEY)
    {
        if (data->max_iters > 10)
            data->max_iters -= 10;
    }
    else if (key_code == O_KEY)
    {    
        if (data->max_iters < 4000)
            data->max_iters += 10;
    }
}

int     handle_key(int key_code, t_data *data)
{
    if (key_code == ESC)
        exit_program(data);
    else if (key_code == L_ARR)
		data->offset_x -= 50 / data->zoom;
	else if (key_code == R_ARR)
		data->offset_x += 50 / data->zoom;
	else if (key_code == U_ARR)
		data->offset_y -= 50 / data->zoom;
	else if (key_code == D_ARR)
		data->offset_y += 50 / data->zoom;
	else if (key_code == A_KEY)
		data->color += 50;
	else if (key_code == O_KEY || key_code == P_KEY)
		iterate(data, key_code);
	render_fractal(data);
	return (0);
}

int     handle_mouse(int mouse_code, int x, int y, t_data *data)
{
    if (mouse_code == SCROLL_UP)
        apply_zoom(data, x, y, 1);
    else if (mouse_code == SCROLL_UP)
        apply_zoom(data, x, y, -1);
    render_fractal(data);
    return (0);
}

