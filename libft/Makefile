# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctilda <ctilda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/20 17:00:07 by ctilda            #+#    #+#              #
#    Updated: 2020/11/20 17:05:37 by ctilda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

TMP =	ft_bzero.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strjoin.c \
	ft_substr.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_itoa.c \
	ft_strtrim.c \
	ft_split.c \
	ft_strmapi.c \

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \

OBJ = ${TMP:.c=.o}
OBJB = $(BONUS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJB)
	ar rcs $(NAME) $(OBJ) $(OBJB)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
