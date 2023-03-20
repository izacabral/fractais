SRCS	=	utils_mlx.c \
			colors.c \
			sets.c \
			render.c \
			hooks.c \
			fractais.c \
			validations.c \

OBJS	=	$(SRCS:.c=.o)

NAME	=	fractais

LIBC	=	mylibc.a

CC		=	cc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -O3

MLXFLAGS	=	 -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

MLIBC	=	make -C mylibc && cp mylibc/$(LIBC) $(LIBC)

MMLX	=	make -C mlx 

MLX		=	mlx/libmlx.a

RMLIBFT	=	make -C mylibc clean

RMMLX	=	make -C mlx clean

FCLIBFT	=	make -C mylibc fclean

.c.o: 
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(LIBC):	
			$(MLIBC)

$(MLX):
			$(MMLX)

$(NAME):	$(LIBC) $(MLX) $(OBJS)  
			$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBC) -o $(NAME)

bonus:		all

clean:
			$(RM) $(OBJS)
			$(RM) $(LIBC)
			$(RMLIBFT)
			$(RMMLX)
		
fclean:		clean
			$(RM) $(NAME)
			$(RM) $(NAMEB)
			$(FCLIBFT)

re:			fclean all

.PHONY:		all clean fclean re
