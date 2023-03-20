
#ifndef FRACTAIS_H
# define FRACTAIS_H

# include "mylibc/mylibc.h"
# include "mylibc/my_printf/my_printf.h"
# include "mlx/mlx.h"

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define COLOR 8
# define JULIA 38
# define MANDEL 46

typedef struct s_win
{
	void		*mlx;
	void		*win;
	int			winx;
	int			winy;
}				t_win;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_win		win;
}				t_img;

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct s_fractais
{
	char		type;
	int			sizex;
	int			sizey;
	t_complex	c;
	int			i_max;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		zoom;
	t_img		img;
	int			color;
}				t_fractais;

typedef struct s_colors
{
	int	color0;
	int	color1;
	int	color2;
	int	color3;
	int	color4;
}				t_colors;

// validations
void	print_error(void);
void	check_parameters(t_fractais *f, int argc, char **argv);

// utils_mlx
t_win	create_window(t_fractais *f, char *name);
t_img	new_image(t_win win);
int		close_window(t_win *win);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

// colors
int		create_trgb(int t, int r, int g, int b);
void	init_colors(t_colors *colors);
double	pallete(t_fractais *f);

// sets
void	init_fractais(t_fractais *f);
int		mandelbrot(t_fractais *m);
int		julia(t_complex z, t_fractais *j);
void	which_fractais(t_fractais *f, t_img *img);

// render
double	proportion_x(t_win *win, t_fractais *f, double x);
double	proportion_y(t_win *win, t_fractais *f, double y);
void	render_mandelbrot(t_img *img, t_fractais *m);
void	render_julia(t_img *img, t_fractais *j);

// hooks
int		key_hook(int keycode, t_fractais *f);
void	move(int keycode, t_fractais *f);
int		mouse_hook(int button, int mouse_x, int mouse_y, t_fractais *f);
void	zoom_fractais(t_fractais *f, int mouse_x, int mouse_y);
void	position_mouse(t_fractais *f, int mouse_x, int mouse_y);

#endif
