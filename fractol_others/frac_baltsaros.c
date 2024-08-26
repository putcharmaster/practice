typedef struct s_img;
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_length;
	int	endian;
}		t_img;

typedef struct s_set
{
	double	pr;
	double	pi;
	double	new_re;
	double	new_im;
	double	old_re;
	double	old_im;
	double	zoom;
	double	move_x;
	double	move_y;
	int	color;
	int	iter;
}		t_set;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_set	set;
	int	
}
