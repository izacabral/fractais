SRCS		=	my_isalpha.c my_isdigit.c my_isalnum.c my_isascii.c \
				my_isprint.c my_toupper.c my_tolower.c \
				my_isspacetab.c \
				my_strncmp.c my_memcmp.c my_atoi.c my_atoi_base.c \
				my_strtol.c my_atol.c \
				my_atof.c my_strlen.c \
				my_strlcpy.c my_strlcat.c my_bzero.c my_striteri.c\
				my_putchar_fd.c my_putstr_fd.c my_putendl_fd.c \
				my_putnbr_fd.c my_swap.c \
				my_memset.c my_memcpy.c my_memmove.c \
				my_memchr.c my_calloc.c my_strchr.c my_strrchr.c \
				my_strnstr.c my_strdup.c my_substr.c \
				my_strjoin.c my_strjoin_free.c my_strtrim.c my_itoa.c \
				my_strmapi.c my_split.c \
				my_lstnew.c my_lstlast.c my_lstmap.c \
				my_lstadd_front.c my_lstadd_back.c my_lstdelone.c \
				my_lstiter.c my_lstclear.c my_lstsize.c \
			
OBJS		= $(SRCS:.c=.o)

NAME		= mylibc.a

CC			= cc

LIBC		= ar rc

LIBR		= ranlib

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

MY_PRINTF	= make -C my_printf && cp my_printf/mylibprintf.a $(NAME)

RMPRINTF	= make -C my_printf clean

FCPRINTF	= make -C my_printf fclean

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(NAME):	$(OBJS) 
			$(LIBC) $(NAME) $(OBJS)
			$(LIBR) $(NAME)
			$(MY_PRINTF)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			$(RMPRINTF)

fclean:		clean
			$(RM) $(NAME)
			$(FCPRINTF)

re:			fclean all

.PHONY:		all clean fclean re

