# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 15:43:57 by lmicheli          #+#    #+#              #
#    Updated: 2024/04/26 15:53:17 by lmicheli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Polymerization

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp

OBJS = $(SRCS:.cpp=.o)

CC = clang++ -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re