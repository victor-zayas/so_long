# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 15:59:46 by vzayas-s          #+#    #+#              #
#    Updated: 2022/09/16 19:26:47 by vzayas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME #
NAME = so_long

# COMPILATION #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
RM = /bin/rm -rf

# OBJS #
OBJS = $(SRCS:.c=.o)

# INCLUDES #
INCLUDE = -I so_long.h

# SRCS #
SRCS = so_long.c		\
	   check_map.c		\
	   libft/split.c	\
	   libft/substr.c	\
	   libft/strlen.c	\

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
END=\033[0m

define SO_LONG

   ▄████████  ▄██████▄        ▄█        ▄██████▄  ███▄▄▄▄      ▄██████▄  
  ███    ███ ███    ███      ███       ███    ███ ███▀▀▀██▄   ███    ███ 
  ███    █▀  ███    ███      ███       ███    ███ ███   ███   ███    █▀  
  ███        ███    ███      ███       ███    ███ ███   ███  ▄███        
▀███████████ ███    ███      ███       ███    ███ ███   ███ ▀▀███ ████▄  
         ███ ███    ███      ███       ███    ███ ███   ███   ███    ███ 
   ▄█    ███ ███    ███      ███▌    ▄ ███    ███ ███   ███   ███    ███ 
 ▄████████▀   ▀██████▀       █████▄▄██  ▀██████▀   ▀█   █▀    ████████▀  
                             ▀                                           

endef
export SO_LONG	

# RULES #

.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDE)
	echo "$(BLUE)༺ library created༻$(END)"
	echo "$$SO_LONG"

clean:
	$(RM) $(OBJS)
	echo "$(RED)༺ Objs deleted༻$(END)"

fclean: clean
	$(RM) $(NAME)
	echo "$(YELLOW)༺ Executable deleted༻$(END)"

re: fclean all

.PHONY: all clean fclean re