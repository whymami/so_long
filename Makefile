NAME = so_long
PRINTF_PATH = lib/ft_printf
LIBFT_PATH = lib/libft
GET_NEXT_LINE_PATH = lib/get_next_line
GET_NEXT_LINE_UTILS_PATH = lib/get_next_line
MLX_PATH = lib/mlx
MLX = $(MLX_PATH)/libmlx.a
LIBFT = $(LIBFT_PATH)/libft.a
GET_NEXT_LINE = $(GET_NEXT_LINE_PATH)/get_next_line.c
GET_NEXT_LINE_UTILS = $(GET_NEXT_LINE_UTILS_PATH)/get_next_line_utils.c
PRINTF = $(PRINTF_PATH)/libftprintf.a
SRC = \
	main.c \
	control1.c \
	control2.c \
	img_and_wndw.c \
	map_check.c \
	move.c \
	utils.c \
	utils2.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(LIBFT) $(GET_NEXT_LINE) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) $(GET_NEXT_LINE) $(GET_NEXT_LINE_UTILS) $(MLX) $(LDFLAGS) -o $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	$(MAKE) -C $(MLX_PATH)

clean:
	$(MAKE) -C $(PRINTF_PATH) clean
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(PRINTF_PATH) fclean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re