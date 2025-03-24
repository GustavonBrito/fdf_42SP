CC = cc

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libftprintf.a

HEADER = -I $(LIBFT_DIR)

NAME = open

SRCS = open_x.c

OBJS = open

CFLAGS = -Werror -Wall -Wextra

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

open: $(LIBFT)
	$(CC) $(CFLAGS) open_x.c -o open_x $(LIBFT)

clean:
	@make -C $(LIBFT_DIR) clean

fclean:
	@make -C $(LIBFT_DIR) fclean
	rm -f $(OBJS) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re

#valgrind cc open_x.c -Lminilibx -lmlx_Linux -lX11 -lXext -lm