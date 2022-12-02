PARSEDIR = parse
SRC = main.c ft_fill.c get_next_line.c \
ft_get_map_len.c ft_render_win.c ft_create_win.c\
ft_check_name.c ft_check_map.c ft_check_utils.c\
ft_check_len.c ft_check_characters.c ft_check_surounded.c \
ft_check_ecp.c ft_get_collec_nb.c ft_input.c ft_check_path.c \
ft_finish.c ft_printf.c ft_animation.c ft_move_enemy.c \
ft_check_first.c 

OBJ = $(SRC:.c=.o)

NAME = so_long
RM = rm -rf
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m
CFLAGES = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :$(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(BLUE)██████████████████████ Compiling is DONE ███████████████████████$(RESET)"
%.o:%.c
	@echo "$(BLUE)██████████████████████     Compiling     ███████████████████████$(RESET)"
	@echo "$(BLUE)█ $(YELLOW)Compiling$(RESET) $<:\r\t\t\t\t\t\t\t$(GREEN){DONE}$(BLUE) █$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)████████████████████  Object files cleaned  ████████████████████$(RESET)"
	@$(RM) $(OBJ)

fclean: clean
	@echo "$(RED)████████████████████     Game cleaned       ████████████████████$(RESET)"	
	@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re