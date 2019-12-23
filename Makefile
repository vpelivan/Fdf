#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/27 16:21:09 by vpelivan          #+#    #+#              #
#    Updated: 2019/03/27 16:21:12 by vpelivan         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC_DIR = ./src/

SRC = main.c bresenham.c keys_set_one.c map.c struct_init_free.c validator.c

OBJ_DIR = ./obj/

OBJ = $(addprefix $(OBJ_DIR),$(SRC:.c=.o))

FLAG = -Wall -Wextra -Werror

FLAG_MLX = -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit

MLX = ./miniLibx_macos/

LIB = ./libft/

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIB)
	@make -C $(MLX)
	@gcc $(FLAG) -I /usr/local/include $(OBJ) $(LIB)libft.a $(FLAG_MLX) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(FLAG) -o $@ -c $<

clean :
	@make -C $(LIB) clean
	@make -C $(MLX) clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(OBJ)

fclean : clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)
re : fclean all