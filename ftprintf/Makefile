# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafranco <mafranco@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 13:06:34 by mafranco          #+#    #+#              #
#    Updated: 2023/07/25 12:17:52 by mafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

LIB = ft_printf.h

SRC	=	ft_printf.c ft_pfptr.c ft_pfchar.c ft_pfint.c

CC	=	cc

CFLAGS	=	-Werror -Wall -Wextra -I.

RM	=	rm -f

OBJ = $(SRC:.c=.o)

OBJ_DIR =	.obj

GREEN	=	\033[1;32m
YELLOW	=	\033[1;33m
RESET	=	\033[0m

all:	$(NAME)

%.o: %.c $(LIB)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):: $(OBJ) $(LIB) $(OBJ_DIR)
	@ar rcs $(NAME) $(OBJ)
	@mv *.o $(OBJ_DIR)

$(NAME)::
	@echo "$(GREEN)ftprintf.a compiled$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(YELLOW)objects of ftprintf removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
