
#include "fractais.h"

t_win	create_window(t_fractais *f, char *name)
{
	t_win	win;

	win.winx = f->sizex;
	win.winy = f->sizey;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.winx, win.winy, name);
	return (win);
}

t_img	new_image(t_win win)
{
	t_img	image;

	image.win = win;
	image.img = mlx_new_image(win.mlx, win.winx, win.winy);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, \
			&image.line_length, &image.endian);
	return (image);
}

int	close_window(t_win *win)
{	
	if (win)
	{
		mlx_clear_window(win->mlx, win->win);
		mlx_destroy_window(win->mlx, win->win);
	}
	exit(EXIT_FAILURE);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img->win.winx && y < img->win.winy)
	{
		dst = img->addr + (y * img->line_length + x * \
				(img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
