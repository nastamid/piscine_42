/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nastamid <nastamid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:54:42 by nastamid          #+#    #+#             */
/*   Updated: 2024/12/03 23:58:31 by nastamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <X11/keysym.h>
#include <mlx.h>

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

int	get_opposite(int argb)
{
	return (argb ^ 0xFFFFFFFF);
}

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum
{
	NOEVENTMASK = 0L,                      // 0
	KEYPRESSMASK = (1L << 0),              // (1 << 0)
	KEYRELEASEMASK = (1L << 1),            // (1 << 1)
	BUTTONPRESSMASK = (1L << 2),           // (1 << 2)
	BUTTONRELEASEMASK = (1L << 3),         // (1 << 3)
	ENTERWINDOWMASK = (1L << 4),           // (1 << 4)
	LEAVEWINDOWMASK = (1L << 5),           // (1 << 5)
	POINTERMOTIONMASK = (1L << 6),         // (1 << 6)
	POINTERMOTIONHINTMASK = (1L << 7),     // (1 << 7)
	BUTTON1MOTIONMASK = (1L << 8),         // (1 << 8)
	BUTTON2MOTIONMASK = (1L << 9),         // (1 << 9)
	BUTTON3MOTIONMASK = (1L << 10),        // (1 << 10)
	BUTTON4MOTIONMASK = (1L << 11),        // (1 << 11)
	BUTTON5MOTIONMASK = (1L << 12),        // (1 << 12)
	KEYMAPSTATEMASK = (1L << 14),          // (1 << 14)
	EXPOSUREMASK = (1L << 15),             // (1 << 15)
	VISIBILITYCHANGEMASK = (1L << 16),     // (1 << 16)
	STRUCTURENOTIFYMASK = (1L << 17),      // (1 << 17)
	RESIZEREDIRECTMASK = (1L << 18),       // (1 << 18)
	SUBSTRUCTURENOTIFYMASK = (1L << 19),   // (1 << 19)
	SUBSTRUCTUREREDIRECTMASK = (1L << 20), // (1 << 20)
	FOCUSCHANGEMASK = (1L << 21),          // (1 << 21)
	PROPERTYCHANGEMASK = (1L << 22),       // (1 << 22)
	COLORMAPCHANGEMASK = (1L << 23)        // (1 << 23)
};

enum
{
	KEYPRESS = 2,          // 02  KeyPress
	KEYRELEASE = 3,        // 03  KeyRelease
	BUTTONPRESS = 4,       // 04  ButtonPress
	BUTTONRELEASE = 5,     // 05  ButtonRelease
	MOTIONNOTIFY = 6,      // 06  MotionNotify
	ENTERNOTIFY = 7,       // 07  EnterNotify
	LEAVENOTIFY = 8,       // 08  LeaveNotify
	FOCUSIN = 9,           // 09  FocusIn
	FOCUSOUT = 10,         // 10  FocusOut
	KEYMAPNOTIFY = 11,     // 11  KeymapNotify
	EXPOSE = 12,           // 12  Expose
	GRAPHICSEXPOSE = 13,   // 13  GraphicsExpose
	NOEXPOSE = 14,         // 14  NoExpose
	VISIBILITYNOTIFY = 15, // 15  VisibilityNotify
	CREATENOTIFY = 16,     // 16  CreateNotify
	DESTROYNOTIFY = 17,    // 17  DestroyNotify
	UNMAPNOTIFY = 18,      // 18  UnmapNotify
	MAPNOTIFY = 19,        // 19  MapNotify
	MAPREQUEST = 20,       // 20  MapRequest
	REPARENTNOTIFY = 21,   // 21  ReparentNotify
	CONFIGURENOTIFY = 22,  // 22  ConfigureNotify
	CONFIGUREREQUEST = 23, // 23  ConfigureRequest
	GRAVITYNOTIFY = 24,    // 24  GravityNotify
	RESIZEREQUEST = 25,    // 25  ResizeRequest
	CIRCULATENOTIFY = 26,  // 26  CirculateNotify
	CIRCULATEREQUEST = 27, // 27  CirculateRequest
	PROPERTYNOTIFY = 28,   // 28  PropertyNotify
	SELECTIONCLEAR = 29,   // 29  SelectionClear
	SELECTIONREQUEST = 30, // 30  SelectionRequest
	SELECTIONNOTIFY = 31,  // 31  SelectionNotify
	COLORMAPNOTIFY = 32,   // 32  ColormapNotify
	CLIENTMESSAGE = 33,    // 33  ClientMessage
	MAPPINGNOTIFY = 34,    // 34  MappingNotify
	GENERICEVENT = 35,     // 35  GenericEvent
	LASTEVENT = 36         // 36  LASTEvent
};

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

int	close(int keycode, t_vars *vars)
{
	(void)keycode;
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

int	handle_mouse_enter(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	ft_printf("Hello \n");
	return (0);
}

int	handle_mouse_leave(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	ft_printf("Bye\n");
	return (0);
}

int	mouse_hook(int mousecode, t_vars *vars)
{
	(void)vars;
	switch (mousecode)
	{
	case 1:
		ft_printf("Mouse Left \n");
		break ;
	case 2:
		ft_printf("Mouse Middle \n");
		break ;
	case 3:
		ft_printf("Mouse Right \n");
		break ;
	case 4:
		ft_printf("Scroll Up \n");
		break ;
	case 5:
		ft_printf("Scroll Down \n");
		break ;
	default:
		break ;
	}
	return (0);
}

int	mouse_move(int x, int y, void *vars)
{
	(void)vars;
	ft_printf("Mouse Position x:%d, y:%d \n", x, y);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	(void)vars;

	ft_printf("Frame\n");
	return (0);
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
		my_mlx_pixel_put(&img, x + 100, y, get_opposite(create_argb(255, x, y,
					i)));
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// usage:
	// mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	mlx_key_hook(vars.win, &handle_input, &vars);
	// mlx_hook(vars.win, ON_MOUSEDOWN, 1L<<0, handle_enter_window, &vars);
	// mlx_hook(vars.win, ON_MOUSEUP, 1L<<0, handle_leave_window, &vars);
	// mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_hook(vars.win, ON_MOUSEMOVE, POINTERMOTIONMASK, mouse_move, &vars);
	mlx_hook(vars.win, ENTERNOTIFY, ENTERWINDOWMASK, handle_mouse_enter, &vars);
	mlx_hook(vars.win, LEAVENOTIFY, LEAVEWINDOWMASK, handle_mouse_leave, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
}
