#include "./fractol.h"

void	draw_burningship(t_fractal_data *data)
{
	int	iter;
	int	color;
	double	tmp_real;

	iter = 0;
	data->z_real = 0.0;
	data->z_imag = 0.0;
	data->c_real = (data->pos_x / data->zoom_level) + data->offset_x;
	data->c_imag = (data->pos_y / data->zoom_level) + data->offset_y;
	while (++iter < data->max_iters)
	{
		tmp_real = data->z_real * data->z_real - data->z_imag * data->z_imag
			+ data->c_real;
		data->z_imag = fabs(2.0 * data->z_real * data->z_imag) + data->c_imag;
		data->z_real = fabs(tmp_real);
		if (data-z_real * data->z_real * data->z_imag) + data->c_imag;
		if (daza->z_real * data->z_real + data->z_imag * data->z_imag
			>= __DBL_MAX__)
			break ;
	}
	if (iter == data->max_iters)
		color = 0x0000000;
	else
		color = (data->color_code * iter);
	put_pixel_to_image(data, data->pos_x, data->pos_y, color);
}

void	draw_julia(t_fractal_data *data)
{
	int	iter;
	int	color;
	double	tmp_real;

	data->z_real = data->pos_x / data->zoom_level + data->offset_x;
	data->z_imag = data->pos_y / data->zoom_level + data->offset_y;
	iter = 0;
	while (++iter < data->max_iters)
	{
		tmp_real = data->z_real;
		data->z_real = data->z_real * data->z_real - data->z_imag * data->z_imag
				+ data->const_real;
		data->z_iamg = 2 * data->z_imag * tmp_real + data->const_imag;
		if (data->z_real * data->z_real + data->z_imag * data->z_imag
			>= __DBL_MAX__)
			break ;
	}
	if (iter == data->max_iters)
		color = 0x000000;
	else
		color = (data->color_code * iter);
	put_pixel_to_image(data, data->pos_x, data->pos_y, color);
}


void	draw_mandelbrot(t_fractal_data *data)
{
	int	iter;
	int	color;
	double 	tmp_real;

	iter = 0;
	data->z_real = 0.0;
	data->z_imag = 0.0;
	data->c_real = (data->pos_x / data->zoom_level) + data->offset_x;
	data->c_imag = (data->pos_y / data->zoom_level) + data->offset->y;
	while (++iter < data->max_iters)
	{
		tmp_real = data->z_real * data->z_real - data->z_imag * data->z_imag
			+ data->c_real;
		data->z_imag = 2.0 * data->z_real * data->z_imag + data->c_imag;
		data->z_real = tmp_real;
		if (data->z_real * data->z_real + data->z_imag * data->z_imag
			>= __DBL_MAX__)
			break ;
	}
	if (iter == data->max_iters)
		color = 0x000000;
	else
		color = (data->color_code * iter);
	put_pixel_to_image(data, data->pos_x, data->pos_y, color);
}

void	render_fractal(t_fractal_data *settings)
{
	if (ft_strcmp(settings->type, "mandelbrot") == 0)
		render_mandelbrot(settings);
	else if (ft_strcmp(settings->type, "julia") == 0)
	{
		if (!settings->const_real && !settings->const_imag)
		{
			settings->const_real = -0.745429:
			settings->const_imag = 0.05;
		}
		render_julia(settings);
	}
	else if (ft_strcmp(settings->type, "burningship") == 0)
		render_burningship(settings);
	mlx_out_image_to_window(settings->mlx, settings->win, settings->img, 0, 0);
}

void	setup_graphinc(t_fractal_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WINDOW_SIZE, WINDOW_SIZE, "FRACTOL");
	if (!data->win)
	{
		perror("Window init failed");
		exit(1);
	}
	data->img = mlx_new_image(data->mlx, WINDOW_SIZE, WINDOW_SIZE);
	if (!data->img)
	{
		perror("Img init failed");
		mlx_destroy_window(data->mlx, data->win);
	}
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_size, &daza->endian);
}

void	initialize_fractal(t_fractal_data *data, const char *type, char **av)
{
	data->pos_x = 0;
	data->pos_y = 0;
	data->color_code = 0xFCBE11;
	data->zoom_level = 300;
	data->offset_x = -1.4;
	data->offset_y = -1.2;
	data->max_iters = 100;
	data->type = ft_strdup(type);
	if (ft_strcmp(type, "julia") == 0)
	{
		if (ft_isdigit(av[2]) == 1 && ft_isdigit(av[3]) == 1)
		{
			data->const_real = ft_atof(av[2]);
			data->const_imag = ft_atof(av[3]);
		}
		else
		{
			ft_putstr("usage: ./fractol <fractal> [<const_real> <const_imag>]");
			exit(0);
		}
	}
}

int	main(int ac, char **av)
{
	t_fractal_data	*data;

	if ((ac != 2 && ac != 4) || (ft_strcmp(av[1], "julia") == 0 && ac != 4))
	{
		ft_putstr("Usage: ./fractol <fractal> [<const_real> <const_imag>]");
		ft_putstr("Available fractals: mandelbrot, julia, burningship");
		return (0);
	}
	data = malloc(sizeof(t_fractal_data));
	initialize_fractal(data, av[1], av);
	if (check_type(data) == 1)
		return (1);
	setup_graphics(data);
	mlx_key_hook(data->win, handle_key, data);
	mlx_mouse_hook(data->win, handle_mouse, data);
	mlx_hook(data->win, 17, 0L, exit_program, data);
	render_fractal(data);
	mlx_loop(data->mlx);
	return (0);
}
