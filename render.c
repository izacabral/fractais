
#include "fractais.h"

double	proportion_x(t_win *win, t_fractais *f, double x)
{
	double	p_x;

	p_x = (f->x_min) + x * (f->x_max - f->x_min) / win->winx;
	return (p_x);
}

double	proportion_y(t_win *win, t_fractais *f, double y)
{
	double	p_y;

	p_y = (f->y_min) + y * (f->y_max - f->y_min) / win->winy;
	return (p_y);
}

void	render_mandelbrot(t_img *img, t_fractais *m)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	x = 0;
	while (y < img->win.winy)
	{
		x = 0;
		m->c.i = proportion_y(&img->win, m, y);
		while (x < img->win.winx)
		{
			m->c.r = proportion_x(&img->win, m, x);
			i = mandelbrot(m);
			if (i == m->i_max)
				my_mlx_pixel_put(img, x, y, 0X00);
			else
				my_mlx_pixel_put(img, x, y, (pallete(m) * i));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->win.mlx, img->win.win, img->img, 0, 0);
}

void	render_julia(t_img *img, t_fractais *j)
{
	t_complex	z;
	int			x;
	int			y;
	int			i;

	y = 0;
	i = 0;
	x = 0;
	while (y < img->win.winy)
	{
		x = 0;
		z.i = proportion_y(&img->win, j, y);
		while (x < img->win.winx)
		{
			z.r = proportion_x(&img->win, j, x);
			i = julia(z, j);
			if (i == j->i_max)
				my_mlx_pixel_put(img, x, y, 0X00);
			else
				my_mlx_pixel_put(img, x, y, (pallete(j) * i));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img->win.mlx, img->win.win, img->img, 0, 0);
}
