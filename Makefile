NAME = so_long
LIBFT = libft/libft.a

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx -lz -framework OpenGL -framework AppKit

SRC = src/main.c \
      src/parse_map.c \
      src/game_init.c \
      src/player_move.c \
      src/utils.c \
      src/path_finder.c \
	  # Add your other .c files here

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft/

$(NAME): $(OBJ)
	make -C mlx/
	$(CC) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -Ilibft -c $< -o $@

clean:
	make clean -C mlx/
	make clean -C libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
