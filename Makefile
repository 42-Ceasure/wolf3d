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

NAME = wolf3d

SRCDIR=		./src/

SRC=		main.c        \
			init_sdl.c 	   \
			parse.c 		\
			core.c 			 \
			key_events.c 	  \
			mouse_events.c 	   \
			raycasting.c
			      
SRCFIL=		$(addprefix $(SRCDIR),$(SRC))

OBJ = $(SRC:.c=.o)

OBJDIR = ./obj/

LIBFT = ./lib/libft/

LIBFTEXE = $(LIBFT)libft.a

SDL_FW = ./lib/SDL2.framework/SDL2

all:    $(NAME)

$(NAME): $(addprefix $(OBJDIR),$(OBJ)) $(LIBFTEXE)
		@$(CC) $(CFLAG) -L $(LIBFT) -lft -o $(NAME)\
		$(addprefix $(OBJDIR), $(OBJ)) $(SDL_FW)

$(OBJDIR)%.o: $(SRCDIR)%.c
		@mkdir -p $(OBJDIR)
		@$(CC) $(CFLAG) -I ./ -I  $(LIBFT)  -o $@ -c $<

$(LIBFTEXE): $(LIBFT)
		@make -k -s -C $(LIBFT)	

clean:	
		@rm -Rf  $(OBJDIR)
		@make -C $(LIBFT) clean

fclean: 
		@rm -Rf  $(OBJDIR)	
		@rm -f $(NAME)
		@make -C $(LIBFT) fclean

re:		fclean all

