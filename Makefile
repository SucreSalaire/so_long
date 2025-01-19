NAME = so_long

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -lz -framework OpenGL -framework AppKit

SRC = src/main.c \
      src/parse_map.c \
      src/game_init.c \
      src/player_move.c \
      src/utils.c \
      # Add your other .c files here

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C mlx/
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	make clean -C mlx/
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
