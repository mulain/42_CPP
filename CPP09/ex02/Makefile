# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 14:41:05 by wmardin           #+#    #+#              #
#    Updated: 2023/03/21 09:16:36 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= PmergeMe

CC		= c++
FLAGS	= -Wall -Wextra -Werror -pedantic -std=c++98 -fsanitize=address
RM		= rm -rf

COLOR	= \033[30m
RESET	= \033[0m

SRC		= main.cpp 

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(FLAGS) $(SRC) -o $(NAME)
	@echo "$(COLOR)$(NAME) compiled.$(RESET)"

clean:
	@$(RM) $(OBJ) obj
	@echo "$(COLOR)$(NAME) cleaned.$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(NAME).dSYM

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
