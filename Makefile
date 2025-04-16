NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror 
LIBS = -Lminilibx_opengl_20191021/ -lmlx -framework OpenGL -framework AppKit

SRCS =  main.c utils/hell_math.c utils/libc_funs.c events.c \
	   fractal_render.c init_fract.c utils/atoi_double.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

all: $(NAME)
%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re