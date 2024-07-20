/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangha <sangha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:07:03 by sanhwang          #+#    #+#             */
/*   Updated: 2024/07/20 23:18:05 by sangha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"



void    init_fractal(t_data *data, const char *type, char **av)
{
    data->pos_x = 0;
    data->pos_y = 0;
    data->color = 0x1173FC;
    data->zoom = 300;
    data->offset_x = -1.4;
    data->offset_y = -1.2;
    data->max_iters = 100;
    data->type = ft_strdup(type);
    if (!ft_strcmp(type, "julia"))
    {
        if (ft_isdigit(av[2]) && ft_isdigit(av[3]))
        {
            data->const_r = ft_atof(av[2]);
            data->const_i = ft_atof(av[3]);
        }
        else
        {
            ft_putstr("Usage: ./fractol <fractal> [<const_real> <const_imag>]");
            exit(0);
        }
    }
}

void    init_mlx(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, SIZE, SIZE, "FRACTOL");
    if (!data->win)
    {
        perror("window init failed");
        exit(1);
    }
    data->img = mlx_new_image(data->mlx, SIZE, SIZE);
    if (!data->img)
    {
        perror("img init failed");
        mlx_destroy_window(data->win, data->win);
    }
    data->img_addr = mlx_get_data_addr(data->img, &data->bpp,
                    &data->line_size, &data->endian);
}

static int     intput_check(int ac, char **av)
{
    if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
        || (ac == 4 && !ft_strcmp(av[1], "julia"))
        || (ac == 2 && !ft_strcmp(av[1], "burningship")))
        return (1);
    else
    {
        ft_putstr("Invalid fractal\n");
        ft_putstr("choose among : mandelbrot, julia, burningship");
        return (0);
    }
}

int     main(int ac, char **av)
{
    t_data     *data;

    if (!input_check(ac, av))
        return (0);
    data = malloc(sizeof(t_data));
    if (!data)
    {
        perror("Failed to allocate memory");
        return (1);
    }
    init_fractal(data, av[1], av);
    init_mlx(data);
    mlx_key_hook(data->win, handle_key, data);
    mlx_mouse_hook(data->win, handle_mouse, data);
    mlx_hook(data->win, 17, 0L, exit_program, data);
    render_fractal(data);
    mlx_loop(data->mlx);
    return (0);
}
