# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kafortin <kafortin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 20:32:19 by kafortin          #+#    #+#              #
#    Updated: 2023/03/21 18:12:34 by kafortin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

FILES = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_atoi.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_iswhitespace.c \
		ft_count_words.c \
		ft_absolute.c \
		ft_strcmp.c \
		ft_tablen.c \
		ft_strcpy.c \
		search_and_replace.c \
		ft_gnl.c \
		ft_free_tab.c \
		
OBJS = $(FILES:.c=.o)

RM = @rm -f

.SILENT: $(OBJS)

all: $(NAME)

$(NAME): $(OBJS)
		@echo "Compiling Libft..."
		@ar rcs $(NAME) $(OBJS)
		@echo "Completed!"

clean:
		@echo "Cleaning all object files... 🧹"
		$(RM) $(OBJS)
		@echo "Completed!"
		
fclean: clean
		@echo "Cleaning library... 🧹"
		$(RM) $(NAME)
		@echo "✨ Cleaning complete! ✨"

re: fclean all

add:
	git add $(FILES)
	git add *.h
	git add Makefile

commit:
	git commit -m "$m"

push:
	git push github master

git: add commit push

.PHONY: all clean fclean re add commit push git