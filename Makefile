# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvan-erp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/21 15:51:46 by pvan-erp          #+#    #+#              #
#    Updated: 2016/10/21 15:51:49 by pvan-erp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes
SRC = main.c validate.c convert.c solve.c ft_bzero.c ft_sqrt_ceil.c ft_memcpy.c

.PHONY: all clean fclean re test
	

all: $(NAME)
	

$(NAME): $(SRC) 
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)

clean:
	

fclean: clean
	rm -f $(NAME)

re: fclean all


test:
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) -fsanitize=address
