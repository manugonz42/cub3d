# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jimmy <jimmy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 17:23:36 by manugonz          #+#    #+#              #
#    Updated: 2024/03/01 17:17:13 by jimmy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

INCLUDES = ../inc

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)

SRCS = ft_isascii.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_memchr.c ft_memmove.c ft_memcmp.c ft_strlcpy.c ft_strnstr.c \
		ft_strlcat.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c \
		ft_striteri.c ft_strmapi.c ft_strlcpycat.c ft_skip_spaces.c ft_isspace.c \
		get_next_line.c get_next_line_utils.c ft_free_matrix.c ft_print_matrix.c

BSRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	   	ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BOBJS = $(BSRCS:.c=.o)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $(OBJS) 

bonus: $(BOBJS) $(OBJS)
	ar -rcs $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm -f $(OBJS) $(BOBJS)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)
