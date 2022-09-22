# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 15:59:46 by vzayas-s          #+#    #+#              #
#    Updated: 2022/09/22 05:16:56 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME #
NAME = so_long

# COMPILATION #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
MLX = -framework OpenGL -framework AppKit
RM = /bin/rm -rf

# OBJS #
OBJS = $(SRCS:.c=.o)

# INCLUDES #
INCLUDE = -I so_long.h

# SRCS #
SRCS = so_long.c			\
	   src/check_map.c		\
	   src/check_error.c	\
	   src/print.c			\
	   src/mlx_things.c		\
	   libft/split.c		\
	   libft/substr.c		\
	   libft/strlen.c		\
	   libft/putstr_fd.c	\
	   libft/memset.c		\

# MAKEFILE ART #
# COLORS #
BLACK=\033[0;30m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
MAG=\033[0;35m
CYAN=\033[0;36m
WHITE=\033[0;37m
PAPYRUS=\033[38;5;223m
END=\033[0m

define SO_LONG
$(PAPYRUS)
   ▄████████  ▄██████▄        ▄█        ▄██████▄  ███▄▄▄▄      ▄██████▄  
  ███    ███ ███    ███      ███       ███    ███ ███▀▀▀██▄   ███    ███ 
  ███    █▀  ███    ███      ███       ███    ███ ███   ███   ███    █▀  
  ███        ███    ███      ███       ███    ███ ███   ███  ▄███        
▀███████████ ███    ███      ███       ███    ███ ███   ███ ▀▀███ ████▄  
         ███ ███    ███      ███       ███    ███ ███   ███   ███    ███ 
   ▄█    ███ ███    ███      ███▌    ▄ ███    ███ ███   ███   ███    ███ 
 ▄████████▀   ▀██████▀       █████▄▄██  ▀██████▀   ▀█   █▀    ████████▀  
                             ▀                                           
$(END)
endef
export SO_LONG	

# RULES #

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	echo "mv mlx_warnings to mlx_warnings log file ..."
	$(MAKE) -C ./mlx/ 2> mlx_warnings
	mv ./mlx/libmlx.a .
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) -L . -lmlx $(MLX) -o $(NAME)
	echo "$(BLUE)༺ library created༻$(END)"
	echo "$$SO_LONG"

clean:
	$(MAKE) -C ./mlx/ clean 
	$(RM) $(OBJS) mlx_warnings libmlx.a
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
	echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re
