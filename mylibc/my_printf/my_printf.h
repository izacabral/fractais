
#ifndef MY_PRINTF_H

# define MY_PRINTF_H

# include <stdarg.h>
# include "../mylibc.h"

int	my_printf(const char *format, ...);
int	my_spec_conversion(const char *fmt, int i, va_list args);
int	my_putchar_pf(char c);
int	my_putstr_pf(char *s);
int	my_putnbr_pf(int n);
int	my_putnbru_pf(unsigned int n);
int	my_puthex_pf(unsigned int n);
int	my_puthexx_pf(unsigned int n);
int	my_puthexp_pf(unsigned long int nbr);

#endif
