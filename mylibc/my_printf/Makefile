SRCS		= my_printf.c \
			  my_putchar_pf.c \
			  my_putnbr_pf.c \
			  my_putstr_pf.c \
			  my_putnbru_pf.c \
			  my_puthex_pf.c \
			  my_puthexx_pf.c \
			  my_puthexp_pf.c \
			  my_spec_conversion.c 

OBJS		= $(SRCS:.c=.o)

NAME		= mylibprintf.a

CC			= cc

LIBC		= ar rc

LIBR		= ranlib

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

MYLIBC		= cp ../mylibc.a $(NAME)

.c.o:	
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(MYLIBC)
			$(LIBC) $(NAME) $(OBJS)
			$(LIBR) $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

