
NAME = libftprintf.a
SOURCES = ft_printf.c ft_printf_utils.c ft_printf_utils2.c

OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f
CC = cc

# === Couleurs ===
GREEN = \033[0;32m]
YELLOW = \033[1;33m]
BLUE = \033[1;34m]
RED = \033[0;31m]
CYAN = \033[0;36m]
RESET = \033[0m]

all: $(NAME)
	@echo "$(GREEN)✅ Compilation terminée: $(NAME)$(RESET)"

$(NAME): $(OBJECTS)
	@echo "$(BLUE)📦 Création de la bibliothèque...$(RESET)"
	@$(AR) $(NAME) $(OBJECTS)
	@echo "$(CYAN)📚 $(NAME) créé avec succès.$(RESET)"

%.o: %.c libft.h
	@echo "$(YELLOW)🔧 Compilation de $<...$(RESET)"
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "$(RED)🧹 Suppression des fichiers objets...$(RESET)"
	@$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	@echo "$(RED)✔️ Clean terminé.$(RESET)"

fclean: clean
	@echo "$(RED)🧨 Suppression de la bibliothèque...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(RED)✔️ Fclean terminé.$(RESET)"

re: fclean all

.PHONY: all clean fclean re