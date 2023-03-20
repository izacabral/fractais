
#include "fractais.h"

void	init_fractais(t_fractais *f)
{	
	f->sizex = 800;
	f->sizey = 800;
	f->i_max = 120;
	f->x_min = -2.0;
	f->x_max = 2.00;
	f->y_min = 2.00;
	f->y_max = -2.00;
	f->zoom = 1.0;
	f->color = 0;
	if (f->type == 'm')
	{
		f->c.r = 0;
		f->c.i = 0;
	}
}

int	mandelbrot(t_fractais *m)
{
	t_complex	z;
	t_complex	z_next;
	int			iterations;

	z.r = 0;
	z.i = 0;
	iterations = 0;
	while (z.r * z.r + z.i * z.i <= 2 * 2 && iterations < m->i_max)
	{
		z_next.r = (z.r * z.r) - (z.i * z.i) + (m->c.r);
		z_next.i = (2 * z.r * z.i) + (m->c.i);
		z.r = z_next.r;
		z.i = z_next.i;
		iterations++;
	}
	return (iterations);
}

int	julia(t_complex z, t_fractais *j)
{
	t_complex	z_next;
	int			iterations;

	z_next.r = z.r * z.r;
	z_next.i = z.i * z.i;
	iterations = 1;
	while (z.r * z.r + z.i * z.i <= 2 * 2 && iterations < j->i_max)
	{
		z_next.r = (z.r * z.r) - (z.i * z.i) + (j->c.r);
		z_next.i = (2 * z.r * z.i) + (j->c.i);
		z.r = z_next.r;
		z.i = z_next.i;
		iterations++;
	}
	return (iterations);
}

void	which_fractais(t_fractais *f, t_img *img)
{
	if (f->type == 'j')
		render_julia(img, f);
	if (f->type == 'm')
		render_mandelbrot(img, f);
}
