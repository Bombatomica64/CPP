# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 15:43:57 by lmicheli          #+#    #+#              #
#    Updated: 2024/04/26 18:49:56 by lmicheli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 🔥Primateria🔥 

SRCS = 	main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp \
		ICharacter.cpp IMateriaSource.cpp

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