NAME = fractol

FLAGS = -Wall -Wextra -Werror -g

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/

SRC_FILES = action_complex.c burning_ship.c color_f.c color.c \
julia_set.c main.c mandelbrot.c manegment.c pixel_set.c window.c 
OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

LNK  = -L $(LIBFT_DIR) -lft  \
			-lmlx -framework OpenGL -framework AppKit

all: obj $(LIBFT) $(MINLBX) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@clang $(FLAGS)  -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)
$(MINLBX):
	@make -C $(MINLBX_DIR)

$(NAME): $(OBJ)
	@clang $(OBJ) $(LNK) -lm -o $(NAME)
	@echo "$(NAME) Compiled!?"

clean:
	@rm  ./obj/*
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re