# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 14:41:05 by wmardin           #+#    #+#              #
#    Updated: 2022/12/28 18:54:41 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++
CFLAGS = -g -fsanitize=address
EFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

BLUE	= \033[94m
RESET	= \033[0m

SRC =	megaphone.cpp
OBJ	=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(EFLAGS) $(OBJ) -o $(NAME)
	@echo "$(BLUE)$(NAME) compiled.$(RESET)"

clean:
	@$(RM) $(OBJ) obj
	@echo "$(BLUE)$(NAME) cleaned.$(RESET)"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

git:
	git add .
	git commit -m "auto add & push"
	git push
	@echo "$(BLUE)git auto add & push performed.$(RESET)"

mgit:
	git add .
	@read -p "Enter the commit message: " halp; \
	git commit -m "$$halp"
	git push
	@echo "$(BLUE)git auto add & push with message performed.$(RESET)"

.SILENT: $(OBJ)