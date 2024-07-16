https://github.com/leogaudin/fract-ol/tree/main/src

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	int	x;
	int	y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int	color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int	max_iterations;
}		t_fractal;


void	draw_burningship(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_burningship(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}

void	calculate_julia(t_fractal *fractal)
{
	int	i;
	double	tmp;

	i = 0;
	fractal->name = "julia";
	fractal->zx = fractal->x / fractal->zoom + fractal->offset_x;
	fractal->zy = fractal->y / fractal->zoom + fractal->offset_y;
	while (++i < fratal->max_iterations)
	{
		tmp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2 * fractal->zy * tmp + fractal->cy;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy
			>= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y,
			(fractal->color * (i % 255)));
}

void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}
/*
z vars set to 0
c constants set to the coordinates of the pixel.
the absolute value of z is greater than the system's max values, then
we can assure that the suite will diverge to infinity.
the number of iterations is too high, then we can assure that the
suite will stay stuck in an infinite loop

if the suite diverges, we color it and multiply the color by the number of
iterations to make the mathematical depths more clear to the eye.

*/

void	calculate_mandelbrot(t_fractal *fractal)
{
	int	i;
	double	x_tmp;

	i = 0;
	fractal->name = "mandelbrot";
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iterations)
	{
		x_tmp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = 2.0 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_tmp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy
			>= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y, (fractal->color * i));
}

void	draw_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		while (fractal->y < SIZE)
		{
			calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
}

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->zoom = 300;
	fractal->offset_x = -1.21;
	fractal->offset_y = -1.21;
	fractal->max_iterations = 42;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image, &fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
}


int	draw_fractal(t_fractal *fractal, char *name)
{
	if (!ft_strcmp(name, "mandelbrot"))
		draw_mandelbrot(fractal);
	else if (!ft_strcmp(name, "julia"))
	{
		if (!fractal->cx && !fractal->cy)
		{
			fractal->cx = -0.745429;
			fractal->cy = 0.05;
		}
		draw_julia(fractal);
	}
	else if (!ft_strcmp(name, "burningship"))
		draw_burningship(fractal);
	else
	{
		ft_putstr("Available fractals: mandelbrot, julia, burningship");
		exit_fractal(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
	return (0);
}


int	main(int ac, char **av)
{
	t_fractal	*fractal;

	if (ac != 2)
	{
		ft_putstr("Usage: ./fractol <fractal>");
		ft_putstr("Available fractals: mandelbrot, julia, burningship");
	}
	fractal = malloc(sizeof(t_fractal));
	init_fractal(fractal);
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, av[1]);
	mlx_loop(fractal->mlx);
	return (0);
}
