# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 17:50:51 by mel-bouh          #+#    #+#              #
#    Updated: 2023/12/26 17:31:18 by mel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
SRC = so_long.c ./utils/rendering.c ./utils/ft_movement.c ./utils/get_next_line.c ./utils/renderutils.c\
	./utils/get_next_line_utils.c ./utils/maputils.c ./utils/mapchecker.c ./utils/flood_fill.c ./utils/ft_itoa.c\
	./utils/enemyanim.c ./utils/enemymove.c ./utils/playeranim.c ./ft_printf/ft_printf.c ./ft_printf/ft_format.c \
	./ft_printf/ft_putstr.c ./ft_printf/ft_putnbr.c ./ft_printf/ft_putchar.c
OBJ = *.o
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	cc $(MLXFLAGS) $(OBJ) -o $(NAME)
$(OBJ): $(SRC)
	cc $(FLAGS) -c $(SRC)
clean: $(OBJ)
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
