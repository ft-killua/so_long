PARSEDIR = parse
FILES = main.c parse/fill_map.c parse/get_next_line.c \
parse/get_len.c parse/render_win.c parse/create_win.c\
check/ft_check_name.c check/ft_check_map.c check/ft_check_utils.c\
check/ft_check_len.c check/ft_check_characters.c check/ft_check_surounded.c \
check/ft_check_ecp.c check/ft_get_collec_nb.c ft_input.c

NAME = so_long
RM = rm -rf
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m
CFLAGES = -Wall -Wextra -Werror

$(NAME): $(FILES)
	@$(CC) $(CFLAGS) $(FILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(BLUE)██████████████████████ Compiling is DONE ███████████████████████$(RESET)"