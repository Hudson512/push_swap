# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmateque <hmateque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 10:01:52 by hmateque          #+#    #+#              #
#    Updated: 2024/07/16 15:27:19 by hmateque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
FLAGS = -Werror -Wall -Wextra -g
SOURCE  =  srcs/*.c \
           *.c \
           
$(NAME):
	$(CC) $(FLAGS) $(SOURCE) -Iincludes -o $(NAME)
all: $(NAME)

clean:
	@rm -rf srcs/*.o
	@rm -rf *.o
fclean: clean
	@rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re