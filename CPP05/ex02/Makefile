# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 14:41:05 by wmardin           #+#    #+#              #
#    Updated: 2023/01/28 23:25:12 by wmardin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= feierabend

CC		= c++
CFLAGS	= #-g -fsanitize=address
EFLAGS	= -Wall -Wextra -Werror -pedantic -std=c++98
RM		= rm -rf

BLUE	= \033[94m
RESET	= \033[0m

SRC		= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp
#OBJ	= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): #$(OBJ)
	@$(CC) $(CFLAGS) $(EFLAGS) $(SRC) -o $(NAME)
	@echo "$(BLUE)$(NAME) compiled.$(RESET)"

clean:
	@$(RM) $(OBJ) obj
	@echo "$(BLUE)$(NAME) cleaned.$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(NAME).dSYM

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

#.SILENT: $(OBJ)