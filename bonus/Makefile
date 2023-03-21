# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 20:32:19 by kafortin          #+#    #+#              #
#    Updated: 2023/03/21 15:13:20 by kafortin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long.a

FILES = end_game_options_bonus.c \
		exit_management_bonus.c \
		flood_fill_bonus.c \
		init_bonus.c \
		moves_counter_bonus.c \
		moves_utils_bonus.c \
		moves_bonus.c \
		put_images_bonus.c \
		read_map_bonus.c \
		so_long_bonus.c \
		validate_map_bonus.c \

OBJS = $(FILES:.c=.o)

RM = @rm -f

.SILENT: $(OBJS)

all: $(NAME)

$(NAME): $(OBJS)
		@$(MAKE) -C ../Libft
		@echo "Compiling so_long..."
		@$(CC) $(CFLAGS) $(OBJS) ../Libft/libft.a ../minilibx_opengl_20191021/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)
		@echo "Completed! 🤠"

clean:
		@$(MAKE) clean -C ../Libft
		$(RM) $(OBJS)
		
fclean: 
		@$(MAKE) fclean -C ../Libft
		$(RM) $(OBJS)
		$(RM) $(NAME)

re: fclean all

add:
	git add $(FILES)
	git add *.h
	git add Makefile

commit:
	git commit -m "$m"

push:
	git push origin master

git: add commit push

.PHONY: all bonus clean fclean re add commit push git