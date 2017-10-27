#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: semartin <semartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 14:06:48 by semartin          #+#    #+#              #
#    Updated: 2016/02/12 14:18:33 by semartin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
SRC_DIR	= ./srcs/
SRC = free.c malloc_large.c malloc_small.c malloc_tiny.c malloc.c \
		page_index.c realloc.c show_mem.c extern.c
VPATH	= $(SRC_DIR)
OBJ = $(addprefix $(O_DIR)/,$(SRC:.c=.o))
O_DIR = ./obj
FLAGS = -Wall -Wextra -Werror
LIB = libft 

all: $(NAME) 

$(NAME): $(OBJ)
	@echo "Making libft."
	@make -C libft/
	@echo "Library made."
	@gcc -shared -o $(NAME) $(OBJ) -I includes/ -L libft/ -lft
	@ln -s $(NAME) libft_malloc.so

$(O_DIR)/%.o: %.c
	@mkdir -p $(O_DIR)
	@gcc $(FLAGS) -I includes -I libft/include -o $@ -c $<

clean:
	@echo "Removing objets."
	@rm -f $(OBJ)
	@echo "Clean done."

fclean: clean
	@echo "Removing library."
	@rm -f $(NAME) libft_malloc.so
	@echo "Fclean done."

re: fclean all

.PHONY : all clean fclean re
