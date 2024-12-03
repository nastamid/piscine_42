/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:54:42 by nastamid          #+#    #+#             */
/*   Updated: 2024/12/03 23:25:14 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ft_printf.h"
#include <X11/keysym.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_a(int argb)
{
	return ((argb >> 24) & 0xFF);
}

int	get_r(int argb)
{
	return ((argb >> 16) & 0xFF);
}

int	get_g(int argb)
{
	return ((argb >> 8) & 0xFF);
}

int	get_b(int argb)
{
	return (argb & 0xFF);
}


int	create_argb(unsigned char a, unsigned char r, unsigned char g,
		unsigned char b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int get_opposite (int argb)
{
	return (argb ^ 0xFFFFFFFF);
}

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


int	close(int keycode, t_vars *vars)
{
	(void) keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	handle_input(int keysym, t_vars *vars)
{
    if (keysym == XK_Escape)
		mlx_destroy_window(vars->mlx, vars->win);
	
	ft_printf("Keypress: %d \n", keysym);
    return (0);
}

int	handle_no_event(t_vars *vars)
{
	(void)vars;
    // Needed to terminate the process
    return (0);
}

int handle_enter_window(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	ft_printf("Hello");
	return 0;
}

int handle_leave_window(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	ft_printf("Bye");
	return 0;
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	int		i;
	int		x;
	int		y;


	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");

	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = 0;
	x = 0;
	y = 0;
	while (i < 1000)
	{
		x++;
		y++;
		my_mlx_pixel_put(&img, x, y, create_argb(255, x, y, i));
		my_mlx_pixel_put(&img, x+100, y, get_opposite(create_argb(255, x, y, i)));

		i++;
	}

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// usage:
	//mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_key_hook(vars.win, &handle_input, &vars);
	//mlx_hook(vars.win, ON_MOUSEDOWN, 1L<<0, handle_enter_window, &vars);
	//mlx_hook(vars.win, ON_MOUSEUP, 1L<<0, handle_leave_window, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}

