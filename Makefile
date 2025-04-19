CC = cc

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libftprintf.a

LIBMLX_DIR		= minilibx-linux
LIBMLX_LIB		= $(LIBMLX_DIR)/libmlx_Linux.a

HEADER = -I $(LIBFT_DIR)

NAME = fdf

SRCS =	main.c \
		utils_main.c\
		error_handlers.c\
		validations.c\
		utils_validations.c\
		map_parser.c\
		utils_map_parser.c\
		init_cam.c\
		init_cam_utils.c\
		init_mlx.c\
		mlx_utils.c\
		init_render.c\
		init_render_utils.c

OBJS =	$(SRCS:%.c=$(OBJ_DIR)/%.o)

OBJ_DIR = build

CFLAGS = -Werror -Wall -Wextra
LDFLAGS = -lm -lXext -lX11 -lXrandr

all: $(LIBFT) $(NAME)

$(LIBFT):

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(LIBMLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(LIBMLX_LIB) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBMLX_DIR) clean
	rm -f $(OBJS)

fclean:
	@make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
