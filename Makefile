# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafranco <mafranco@student.barcelona.>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 15:02:38 by mafranco          #+#    #+#              #
#    Updated: 2023/09/19 16:24:14 by mafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIBFT_PATH	=	libft/
LIBPF_PATH	=	ftprintf/

LIBFT_LIB	=	$(LIBFT_PATH)libft.a
LIBPF_LIB	=	$(LIBPF_PATH)libftprintf.a

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC	=	src/checkpath.c src/checkmap.c src/init.c src/key.c src/so_long.c \
		src/createmap.c

MLX_EX	=	$(MLX_LIB) $(MLX_FLAG)

CC	=	cc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -I.

OBJ	=	$(SRC:.c=.o)


all: makelib $(NAME)

%.o:	%.c $(LIB)
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $<

makelib:
	@make -C $(MLX_PATH)
	@make -C $(LIBFT_PATH)
	@make -C $(LIBPF_PATH)
	@echo "mlx, libft, libftprintf compiled"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) $(MLX_LIB) $(LIBFT_LIB) $(LIBPF_LIB) -o $(NAME)
	@echo "so_long created"


clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@make -C $(LIBPF_PATH) clean
	@rm -f $(OBJ)
	@echo "objects removed"


fclean:	clean
	@$(RM) $(NAME)
	@make -C $(MLX_PATH) fclean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(LIBPF_PATH) fclean
	@rm -f $(NAME)
	@echo "so_long removed"

re:	fclean all

.PHONY: all clean fclean re
