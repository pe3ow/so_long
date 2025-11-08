
NAME        = so_long
NAME_BONUS  = so_long_bonus

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iheader -Ift_printf -Iminilibx-linux

MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11

SRC_DIR     = src
SRC_FILES   = checkmap.c draw_map.c exit.c floodfill.c main.c movements.c \
			  split.c utils.c utils2.c
SRC         = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

BONUS_DIR   = bonus/src
BONUS_FILES = checkmap_bonus.c draw_map_bonus.c exit_bonus.c main_bonus.c \
			  movements_bonus.c split_bonus.c utils_bonus.c utils2_bonus.c \
			  floodfill_bonus.c utils3_bonus.c
BONUS_SRC   = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

FT_PRINTF_DIR = ft_printf
FT_PRINTF_SRC = $(addprefix $(FT_PRINTF_DIR)/, ft_printf.c ft_printf_utils.c ft_printf_utils2.c)
FT_PRINTF_OBJ = $(FT_PRINTF_SRC:.c=.o)

OBJ         = $(SRC:.c=.o) $(FT_PRINTF_OBJ)
OBJ_BONUS   = $(BONUS_SRC:.c=.o) $(FT_PRINTF_OBJ)

all: $(MLX_LIB) $(NAME)

bonus: CFLAGS += -Ibonus/header
bonus: $(MLX_LIB) $(NAME_BONUS)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)
	@echo "✅ Compilation de $(NAME) terminée !"

$(NAME_BONUS): $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "🎯 Compilation de $(NAME_BONUS) terminée !"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)
	@echo "🧹 Fichiers objets supprimés."

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "🧼 Exécutables supprimés."

re: fclean all

rebonus : fclean bonus

.PHONY: all clean fclean re bonus
