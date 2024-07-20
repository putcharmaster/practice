/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:05:40 by sanhwang          #+#    #+#             */
/*   Updated: 2024/07/20 23:58:50 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define SIZE 800
//X11 keycode
# define ESC 65307
# define L_ARR 65361
# define R_ARR 65363
# define U_ARR 65362
# define D_ARR 65364
# define A_KEY 97
# define Z_KEY 122
# define O_KEY 111
# define P_KEY 112
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *img_addr;
    char    *type;
    int         bpp;
    int         line_size;
    int         endian;
    int     max_iters;
    double  pos_x;
    double  pos_y;
    double  color;
    double  zoom;
    double  offset_x;
    double  offset_y;
    double  const_r;
    double  const_i;
    double  z_r;
    double  z_i;
    double  c_r;
    double  c_i;
}           t_data;

//main.c
void    init_mlx(t_data *data);
void    init_fractal(t_data *data, const char *type, char **av);

//str_util.c
char    *ft_strdup(const char *src);
void    ft_putstr(char *str);
int     ft_isdigit(char *str);
int     ft_strcmp(const char *s1, char *s2);

//ft_atof.c
double ft_atof(const char *str);

//data_util.c
int     exit_program(t_data *data);
void    put_pixel_to_image(t_data *data, int x, int y, int color);
int     handle_key(int  key_code, t_data *data);
int     handle_mouse(int mouse_code, int x, int y, t_data *data);

//render.c
void    apply_zoom(t_data *data, int x, int y, int direction);
void    render_fractal(t_data *data);
void	rendering(t_data *data);

//fractal.c
void	draw_mandelbrot(t_data *data);
void	draw_julia(t_data *data);
void	draw_burningship(t_data *data);

#endif