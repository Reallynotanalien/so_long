# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 20:32:19 by kafortin          #+#    #+#              #
#    Updated: 2023/03/17 16:55:35 by kafortin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

NAME = so_long

FILES = destroy.c \
		end_game_options.c \
		exit_management.c \
		flood_fill.c \
		init.c \
		moves_counter.c \
		moves.c \
		moves_utils.c \
		read_map.c \
		so_long.c \
		utils2.c \
		validate_map.c \

OBJS = $(FILES:.c=.o)

RM = @rm -f

.SILENT: $(OBJS)

all: $(NAME)

$(NAME): $(OBJS)
		@$(MAKE) -C ./Libft
		@echo "Compiling so_long..."
		@$(CC) $(CFLAGS) $(OBJS) ./Libft/libft.a ./minilibx_opengl_20191021/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)
		@echo "Completed! 🤠"

clean:
		@$(MAKE) clean -C ./Libft
		$(RM) $(OBJS)
		
fclean: 
		@$(MAKE) fclean -C ./Libft
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