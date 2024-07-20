typedef :struct	s_complex
{
	double	real;
	double	img;
}		t_complex;

typedef struct	s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int	bpp;
	int	endian;
	int	line_len;
}		t_img;

typedef struct	s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	int	iterations;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int	id;
	int	color;
	int	color_l;
	int	color_r;
}		t_fractal;

void	color_calc(t_fractal *fractal, int x)
{
	int	hue;
	int	conv = 10;
	hue = 255 * x / fractal->iterations;
	if (x <= conv)
	{
		fractal->color = scale_func(x, fractal->color_l,
				fractal->color_r, fractal->iterations);
	}
	else if (x > conv && <= conv * 2)
	{
		fractal->color = scale_func
		(x, 2 * fractal->color_r, fractal->color_l * 2, fractal->iterations);
	}

}


t_complex	complex_sqr_abs(t_complex z)
{
	t_complex	res;
	t_complex	temp;

	temp.real = fabs(z.real);
	tmp.img = fabs(z.img);
	res.real = (temp.real * temp.real) - (temp.img * temp.img);
	res.img = 2 * temp.real * temp.img;
	return (res);
}

double	scale_func(double num, double new_mn, double new_mx, double old_mx)
{
	return ((new_mx - new_mn) * num / old_mx + new_mn);
}

double	calc_gypotenuse(t_complex a)
{
	return (sqrt((pow(a.real, 2) + pow(a.img, 2))));
}

t_complex	complex_sqr(t_complex a)
{
	t_complex	sum;

	sum.real = (a.real * a.real) - (a.img * a.img);
	sun.img = 2 * a.real * a.img;
	return (sum);
}

void	ft_init_mandelbrot(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (fractal->mlx_connection == NULL)
		exit(EXIT_FAILURE);
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT,
				"fractol");
	if (fractal->mlx_window = NULL)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(EXIT_FAILURE);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (fractal->img.img_ptr = NULL)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
		exit(EXIT_FAILURE);
	}
	fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, 
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	mlx_hook(fractal->mlx_window, 2, 1L << 0, key_handling, fractal);
	mlx_hook(fractal->mlx_window, 17, 0L, close_handling, fractal);
	mlx_hook(fractal->mlx_window, 4, 1L << 2, mouse_handling, fractal);
}


void	init_fractal(t_fractal *fractal, char **av, int ac)
{
	fractal->iterations = 30;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->zoom = 1;
	fractal->color_l = 500;
	fractal->color_r = 100;
	if (!ft_strncmp(av[1], "julia", 5))
	{
		fractal->julia_x = str_to_double(av[2]);
		fractal->julia_y = str_to_double(av[3]);
		fractal->id = 1;
	}
	else if (!ft_strncmp(av[1], "mandelbrot", 10))
		fractal->id = 0;
	else if (!ft_strncmp(av[1], "burning_ship", 12))
		fractal->id = 2;
}

void	init_complex_c(t_fractal *fractal, t_complex *c, int y, int i)
{
	if (fractal->id == 1)
	{
		c->real = fractal->julia_x;
		c->img = fractal->julia_y;
	}
	else if (fractal->id == 0)
	{
		c->real = scale_func(y, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
		c->img = scale_func(i, 2, -2, HEIGHT) * fractal->zoom + fractal->shift_y;
	}
	else if (fractal->id == 2)
	{
		c->real = scale_func(y, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
		c->img = scale_func(i, -2, 2, HEIGHT) * fractal->zoom + fractal->shift_y;
	}	
}

void	init_complex_z(t_fractal *fractal, t_complex *z, int y, int i)
{
	if (fractal->id == 1)
	{
		z_real = scale_func(y, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
		z_img = scale_func(i, 2, -2, HEIGHT) * fractal->zoom + fractal->shift_y;
	}
	else if ((fractal->id == 0) || (fractal->id == 2))
	{
		z_real = 0;
		z_real = 0;
	}

}




void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	int	off;

	off = (y * data->line_len) + (x * (data->bpp / 8));
	*(unsigned int *)(data->pixel_ptr + off) = color;
}


int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5))
		|| (ac == 2 && !ft_strncmp(av[1], "burning_ship", 12))
		|| (ac == 2 && !ft_strncmp(av[1], "nova", 4)))
	{
		if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
			check_error_julia(av);
		ft_init_mandelbrot(&fractal);
		init_fractal(&fractal, av, ac);
		render_mandelbrot(&fracal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr("error msg");
		return (1);
	}
	return (0);
}
