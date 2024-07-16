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

int	main(int ac, char **av)
{
	t_fractal	*fractal;

	if (ac != 2)
	{
		ft_putstr("Usage: 
	}
}
