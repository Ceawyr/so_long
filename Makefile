NAME = so_long

SRCS = $(wildcard *.c) $(wildcard fonction/*.c)

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLXPATH = ./MLX42

HEADERS = -I ./MLX42/include

MLXLIBS = $(MLXPATH)/build/libmlx42.a -ldl -lglfw -pthread -lm

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLXLIBS) -o $(NAME)

all: libmlx $(NAME)

libmlx:
	@cmake $(MLXPATH) -B $(MLXPATH)/build && make -C $(MLXPATH)/build -j4

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(MLXPATH)/build

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

.PHONY: all clean fclean re libmlx