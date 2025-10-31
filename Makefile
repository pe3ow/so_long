
NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a

PRINTF_DIR	= ft_printf
PRINTF_LIB	= $(PRINTF_DIR)/libftprintf.a

INCLUDES	= -I$(MLX_DIR) -I$(PRINTF_DIR) -I.

SRC			= main.c movements.c utils.c draw_map.c checkmap.c split.c \
				exit.c floodfill.c
OBJ			= $(SRC:.c=.o)

MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🧩 Compilation des librairies..."
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@echo "🚀 Compilation de so_long..."
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_LIB) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Compilation terminée : ./so_long"

%.o: %.c so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "🧹 Suppression des fichiers objets..."
	rm -f $(OBJ)
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "🗑 Suppression de l’exécutable..."
	rm -f $(NAME)
	rm -f $(PRINTF_LIB)

re: fclean all

run: all
	./$(NAME) maps/map.ber

.PHONY: all clean fclean re run
