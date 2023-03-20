
#include "fractais.h"

int	key_hook(int keycode, t_fractais *f)
{
	if (keycode == ESC)
		close_window(&f->img.win);
	if (keycode == COLOR)
	{
		f->color++;
	}
	if (keycode == JULIA)
	{
		f->type = 'j';
		f->c.r = 0.285;
		f->c.i = 0.01;
	}
	if (keycode == MANDEL)
		f->type = 'm';
	if (keycode >= 123 && keycode <= 126)
		move(keycode, f);
	mlx_clear_window(f->img.win.mlx, f->img.win.win);
	which_fractais(f, &f->img);
	return (0);
}

void	move(int keycode, t_fractais *f)
{
	if (keycode == LEFT)
	{
		f->x_min += 0.04;
		f->x_max += 0.04;
	}
	if (keycode == RIGHT)
	{
		f->x_min -= 0.04;
		f->x_max -= 0.04;
	}
	if (keycode == UP)
	{
		f->y_min -= 0.04;
		f->y_max -= 0.04;
	}
	if (keycode == DOWN)
	{
		f->y_min += 0.04;
		f->y_max += 0.04;
	}
}

int	mouse_hook(int button, int mouse_x, int mouse_y, t_fractais *f)
{
	if (button == 1)
		init_fractais(f);
	if (button == 2)
		position_mouse(f, mouse_x, mouse_y);
	if (button == 4)
	{
		f->zoom = 0.9;
		zoom_fractais(f, mouse_x, mouse_y);
	}
	if (button == 5)
	{
		f->zoom = 1.1;
		zoom_fractais(f, mouse_x, mouse_y);
	}
	mlx_clear_window(f->img.win.mlx, f->img.win.win);
	which_fractais(f, &f->img);
	return (0);
}

void	zoom_fractais(t_fractais *f, int mouse_x, int mouse_y)
{
	double	x;
	double	y;

	x = proportion_x(&f->img.win, f, mouse_x);
	y = proportion_y(&f->img.win, f, mouse_y);
	f->x_max = x + ((f->x_max - x) * f->zoom);
	f->x_min = x + ((f->x_min - x) * f->zoom);
	f->y_max = y + ((f->y_max - y) * f->zoom);
	f->y_min = y + ((f->y_min - y) * f->zoom);
}

void	position_mouse(t_fractais *f, int mouse_x, int mouse_y)
{
	double	x;
	double	y;
	double	centerx;
	double	centery;

	centerx = (f->x_max + f->x_min) / 2;
	centery = (f->y_max + f->y_min) / 2;
	x = proportion_x(&f->img.win, f, mouse_x) - centerx;
	y = proportion_y(&f->img.win, f, mouse_y) - centery;
	f->x_max += x;
	f->x_min += x;
	f->y_max += y;
	f->y_min += y;
}	
