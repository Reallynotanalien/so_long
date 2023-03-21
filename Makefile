# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 20:32:19 by kafortin          #+#    #+#              #
#    Updated: 2023/03/21 18:12:26 by kafortin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

NAME_BONUS = so_long_bonus

FILES = end_game_options.c \
		exit_management.c \
		flood_fill.c \
		init.c \
		moves_utils.c \
		moves.c \
		put_images.c \
		read_map.c \
		so_long.c \
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

bonus: $(NAME_BONUS)

$(NAME_BONUS):
		@$(MAKE) -C ./Libft
		@$(MAKE) -C ./bonus
		@$(CC) $(CFLAGS) ./Libft/libft.a ./bonus/so_long.a ./minilibx_opengl_20191021/libmlx.a -framework OpenGL -framework AppKit -o $(NAME_BONUS)
		@echo "Completed! 🤠"
		
clean:
		@$(MAKE) clean -C ./Libft
		@$(MAKE) clean -C ./bonus
		$(RM) $(OBJS)
		
fclean: 
		@$(MAKE) fclean -C ./bonus
		@$(MAKE) fclean -C ./Libft
		$(RM) $(OBJS)
		$(RM) $(NAME)
		$(RM) $(NAME_BONUS)

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