
#include "fractais.h"

void	print_error(void)
{
	my_printf("\e[31m---Invalid parameters! Try something like:\n\e[0m");
	my_printf("\e[32m./fractais mandelbrot\n\e[0m");
	my_printf("\e[32m./fractais julia 0.285 0.01\n\e[0m");
	my_printf("\e[32m./fractais julia -0.70176 -0.3842\n\e[0m");
	my_printf("\e[32m./fractais julia -0.4 0.6\n\e[0m");
}

void	check_parameters(t_fractais *f, int argc, char **argv)
{
	if (argc > 1)
	{
		if (my_strncmp(argv[1], "mandelbrot", 11) == 0 && argc == 2)
			f->type = 'm';
		else if (my_strncmp(argv[1], "julia", 6) == 0 && argc == 4)
		{
			f->type = 'j';
			f->c.r = my_atof(argv[2]);
			f->c.i = my_atof(argv[3]);
		}
		else
		{
			print_error();
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		print_error();
		exit(EXIT_FAILURE);
	}
}
