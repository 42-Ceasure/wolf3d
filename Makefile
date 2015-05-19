# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/16 14:40:47 by cglavieu          #+#    #+#              #
#    Updated: 2015/05/19 18:01:20 by cglavieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re

CC = gcc

CFLAG = -Wall -Wextra -Werror

NAME = ./wolf3d

SRCDIR=		./sources/
SRC=		main.c        \
			      
SRCFIL=		$(addprefix $(SRCDIR),$(SRC))

OBJ = $(SRC:.c=.o)
OBJDIR = ./obj/

LIBFT = ./lib/libft/

LIBFTEXE = $(LIBFT)libft.a

MLX = ./lib/minilibx_macos/

MLXEXE = $(MLX)libmlx.a

FW = -framework OpenGL -framework AppKit

all:    $(NAME)

$(NAME): $(addprefix $(OBJDIR),$(OBJ)) $(LIBFTEXE) $(MLXEXE)
		@$(CC) $(CFLAG) -L $(LIBFT)  -lft -L $(MLX) -lmlx -o $(NAME)\
		$(addprefix $(OBJDIR), $(OBJ))  $(FW)

$(OBJDIR)%.o: $(SRCDIR)%.c
		@mkdir -p $(OBJDIR)
		@$(CC) $(CFLAG) -I ./ -I  $(LIBFT)  -c $(SRCFIL) -o $@

$(LIBFTEXE): $(LIBFT)
		@make -k -s -C $(LIBFT)	

$(MLXEXE): $(MLX)
		@make -k -s -C $(MLX)

clean:	
		@rm -Rf  $(OBJ)
		@make -C $(LIBFT) clean
		@make -C $(MLX) clean

fclean: 
		@rm -Rf  $(OBJDIR)	
		@rm -f $(NAME)
		@make -C $(LIBFT) fclean
		@make -C $(MLX) clean

re:		fclean all

