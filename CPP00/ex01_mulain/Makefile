# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 14:41:05 by wmardin           #+#    #+#              #
#    Updated: 2023/02/05 10:54:58 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++
CFLAGS = -g -fsanitize=address
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

COLOR	= \033[30m
RESET	= \033[0m

SRC =	main.cpp Contact.cpp PhoneBook.cpp
OBJ	=	$(SRC:.cpp=.o)
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(COLOR)$(NAME) compiled.$(RESET)"

clean:
	@$(RM) $(OBJ) obj
	@echo "$(COLOR)$(NAME) cleaned.$(RESET)"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

git:
	git add .
	git commit -m "auto add & push"
	git push
	@echo "$(COLOR)git auto add & push performed.$(RESET)"

mgit:
	git add .
	@read -p "Enter the commit message: " halp; \
	git commit -m "$$halp"
	git push
	@echo "$(COLOR)git auto add & push with message performed.$(RESET)"

.SILENT: $(OBJ)