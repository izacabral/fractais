
#include "fractais.h"

int	main(int argc, char **argv)
{
	t_win		win;
	t_fractais	f;

	check_parameters(&f, argc, argv);
	init_fractais(&f);
	win = create_window(&f, "fract`ol");
	f.img = new_image(win);
	which_fractais(&f, &f.img);
	mlx_mouse_hook(win.win, mouse_hook, &f);
	mlx_key_hook(win.win, key_hook, &f);
	mlx_hook(win.win, 17, 1L << 0, close_window, &win);
	mlx_loop(win.mlx);
}
