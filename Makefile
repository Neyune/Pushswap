# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ereali <ereali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/10 16:02:02 by ereali            #+#    #+#              #
#    Updated: 2021/06/11 18:48:33 by ereali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap

INC_DIR = 	$(shell find includes -type d)

INC_LIBFT = libft/
LIB = libft/libft.a

##List every folder where he will find source file
SRC_DIR = 	$(shell find srcs -type d)

##Folder where he will store the .o
OBJ_DIR	= obj

##Add to the vpath the folder find in SRC_DIR
vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

##List every .c found inside SRC_DIR
SRC = ErrorGest.c main.c

##Transform and place every .o from SRC
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

##Basics flags
CFLAGS =	-Wall -Wextra -Werror

##Create the flags to includes every .h needed by this program
IFLAGS =	$(foreach dir, $(INC_DIR), -I$(dir))

##Define the compiler to use
CC =	gcc

all: $(NAME)

$(NAME): $(OBJ)
				make -C libft
				@echo "Compiling $(NAME) ...\c"
				$(CC) $(OBJ) $(CFLAGS) $(IFLAGS) -I libft/ -L libft/ -l ft -o pushswap
				@echo " DONE"

$(OBJ_DIR)/%.o : %.c
				@mkdir -p $(OBJ_DIR)
				@echo "Compiling $< ...\c"
				@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
				@echo " DONE"

clean:
				@rm -rf $(OBJ_DIR)
				@echo "clean"

fclean:			clean
				@rm -f $(NAME)
				@echo "fclean"

re:				fclean all

.PHONY: all clean fclean re
