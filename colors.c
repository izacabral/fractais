
#include "fractais.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	init_colors(t_colors *colors)
{
	colors->color0 = create_trgb(0, 255, 255, 255);
	colors->color1 = create_trgb(0, 10, 10, 255);
	colors->color2 = create_trgb(0, 242, 10, 10);
	colors->color3 = create_trgb(0, 255, 255, 10);
	colors->color4 = create_trgb(0, 30, 80, 50);
}

double	pallete(t_fractais *f)
{
	t_colors	colors;

	init_colors(&colors);
	if (f->color == 0)
		return (colors.color0);
	if (f->color == 1)
		return (colors.color1);
	if (f->color == 2)
		return (colors.color2);
	if (f->color == 3)
		return (colors.color3);
	if (f->color == 4)
		return (colors.color4);
	else
	{
		f->color = 0;
		return (colors.color0);
	}
}
