#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_fractal_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	double	pos_x;
	double	pos_y;
	double	color_code;
	double	zoom_level;
	double	offset_x;
	double	offset_y;
	double	const_real;
	double	const_imag;
	double	z_real;
	double	z_imag;
	double	c_real;
	double	c_imag;
	int		max_iters;
	char	*type;
	int	argc;
}		t_fractal_data;








#endif
