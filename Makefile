# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 15:02:38 by mafranco          #+#    #+#              #
#    Updated: 2023/09/11 15:02:40 by mafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIB	=	include/so_long.h

LIBMLX_PATH	=	/Users/mathis/mlx/
LIBFT_PATH	=	./libft/
LIBPF_PATH	=	./ftprintf/

LIBMLX	=	libmlx.a
LIBFT	=	libft.a
LIBPF	=	libftprintf.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT))
LIBPF_LIB	=	$(addprefix $(LIBPF_PATH), $(LIBPF))
LIBMLX_LIB	=	$(addprefix $(LIBMLX_PATH), $(LIBMLX))

SRC_DIR	=	src
SRC	=	$(wildcard $(SRC_DIR)/*.c)

MLX_FLAG	=	-lX11 -lXext
MLX_EX	=	$(LIBMLX_LIB) $(MLX_FLAG)

CC	=	cc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -I.

OBJ_DIR	=	.obj
OBJ	=	$(SRC:.c=.o)

GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
RESET	=	\033[0m


%.o:	%.c $(LIB)
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

lib:
	@make -C $(LIBFT_PATH)

mlx:
	@make -C $(LIBMLX_PATH)

$(NAME):: lib mlx $(OBJ) $(OBJ_DIR)

	@$(CC) $(CFLAGS) $(OBJ) $(MLX_EX) $(LIBFT_LIB) $(LIBPF_LIB) -o $(NAME)
	@mv $(SRC_DIR)/*.o $(OBJ_DIR)

$(NAME)::
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(YELLOW)objects of so_long removed$(RESET)"

fclean:	clean
	@$(RM) $(NAME)
	make clean -C $(LIBFT_PATH)
	make clean -C $(LIBMLX_PATH)
	@echo "$(YELLOW)$(NAME) removed$(RESET)"

re:	fclean all
	make fclean -C $(LIBFT_PATH)

.PHONY: all clean fclean re
