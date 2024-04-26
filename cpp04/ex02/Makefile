# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 15:43:57 by lmicheli          #+#    #+#              #
#    Updated: 2024/04/26 18:36:15 by lmicheli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 🤮Vomit🤮

SRCS = 	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp \
		Brain.cpp

OBJS = $(SRCS:.cpp=.o)

CC = clang++ -std=c++98 -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re