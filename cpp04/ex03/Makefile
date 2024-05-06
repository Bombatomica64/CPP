# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 15:43:57 by lmicheli          #+#    #+#              #
#    Updated: 2024/05/06 17:32:29 by lmicheli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 🔥Primateria🔥 

SRCS =	AMateria.cpp  	Cure.cpp  ICharacter.cpp      main.cpp \
		Character.cpp 	Ice.cpp   IMateriaSource.cpp  MateriaSource.cpp \
		Floor.cpp		ATile.cpp

CC = clang++ -std=c++98 -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re