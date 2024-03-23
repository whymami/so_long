NAME = so_long
BONUS_NAME = so_long_bonus
PRINTF_PATH = lib/ft_printf
LIBFT_PATH = lib/libft
GET_NEXT_LINE_PATH = lib/get_next_line
GET_NEXT_LINE_UTILS_PATH = lib/get_next_line


LIBFT = $(LIBFT_PATH)/libft.a
GET_NEXT_LINE = $(GET_NEXT_LINE_PATH)/get_next_line.c
GET_NEXT_LINE_UTILS = $(GET_NEXT_LINE_UTILS_PATH)/get_next_line_utils.c
PRINTF = $(PRINTF_PATH)/libftprintf.a

UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	MLX_PATH = lib/mlx_linux
	MLX = $(MLX_PATH)/libmlx.a
	LDFLAGS = -L$(MLX_PATH) -lXext -lX11 -lm -lbsd
	CFLAGS = -Wall -Wextra -Werror -D _KEY_W=119 -D _KEY_A=97 -D _KEY_S=115 -D _KEY_D=100 -D _KEY_ESC=65307
	CLEAR = clear
else
	MLX_PATH = lib/mlx
	MLX = $(MLX_PATH)/libmlx.a
	LDFLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
	CFLAGS = -Wall -Wextra -Werror
	CLEAR = printf "\033c"
endif


SRC = \
	main.c \
	control1.c \
	control2.c \
	img_and_wndw.c \
	map_check.c \
	move.c \
	utils.c \
	utils2.c

BNS_SRC = \
	bonus/main_bonus.c \
	bonus/control1_bonus.c \
	bonus/control2_bonus.c \
	bonus/img_and_wndw_bonus.c \
	bonus/map_check_bonus.c \
	bonus/move_bonus.c \
	bonus/utils_bonus.c \
	bonus/utils2_bonus.c \
	bonus/enemy_bonus.c \

OBJ = $(SRC:.c=.o)
BNS_OBJ = $(BNS_SRC:.c=.o)
CC = gcc
RM = rm -f

BLUE = \033[0;34m
LIGHT_GREEN = \033[1;32m
BOLD = \033[1m
RESET = \033[0m
RED = \033[0;31m
YELLOW = \033[0;33m

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(LIBFT) $(GET_NEXT_LINE) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) $(GET_NEXT_LINE) $(GET_NEXT_LINE_UTILS) $(MLX) $(LDFLAGS) -o $(NAME)
	$(CLEAR)
	@echo "\033[1;34mCompile\033[0m \033[1;32m[Success]\033[0m"
	@echo "$(BLUE)$(BOLD)How to use :$(RESET) $(LIGHT_GREEN)$(BOLD)./so_long maps/<map name>.ber$(RESET)"

bonus: $(BNS_OBJ) $(PRINTF) $(LIBFT) $(GET_NEXT_LINE) $(MLX)
	@$(CC) $(CFLAGS) $(BNS_OBJ) $(PRINTF) $(LIBFT) $(GET_NEXT_LINE) $(GET_NEXT_LINE_UTILS) $(MLX) $(LDFLAGS) -o $(BONUS_NAME)
	$(CLEAR)
	@echo "\033[1;34mCompile\033[0m \033[1;32m[Success]\033[0m"
	@echo "$(BLUE)$(BOLD)How to use :$(RESET) $(LIGHT_GREEN)$(BOLD)./so_long_bonus maps/map_bonus/<map name>.ber$(RESET)"

$(PRINTF):
	@$(MAKE) -C $(PRINTF_PATH)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

clean:
	@$(MAKE) -C $(PRINTF_PATH) clean
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean
	@$(RM) $(OBJ)
	@$(RM) $(BNS_OBJ)
	$(CLEAR)
	@echo "$(RED)$(BOLD)All object files have been deleted.$(RESET)"

fclean: clean
	@$(MAKE) -C $(PRINTF_PATH) fclean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)
	$(CLEAR)
	@echo "$(RED)$(BOLD)Program file have been deleted.$(RESET)"

re: fclean all
	@echo "$(YELLOW)$(BOLD)Program being recompiled.$(RESET)"

.PHONY: all clean fclean re