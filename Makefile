# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 17:16:42 by khelegbe          #+#    #+#              #
#    Updated: 2021/03/16 17:01:36 by khelegbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang

FLAGS		=	-Wall -Wextra -Werror

NAME		=	libftprintf.a

SRCS		=	srcs/ft_printf.c \
				srcs/ft_parse.c \
				srcs/ft_exec_c.c \
				srcs/ft_exec_d_i_u.c \
				srcs/ft_exec_s.c \
				srcs/ft_exec_p.c \
				srcs/ft_exec_x.c \
				srcs/ft_convert_hex.c \
				srcs/ft_utils.c

HEADERS		=	-I include -I libft

OBJECTS		=	${SRCS:.c=.o}

all:			$(NAME)

.c.o:
				@${CC} ${FLAGS} ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME) 	:	${OBJECTS}
				@make -C libft
				@cp libft/libft.a ${NAME}
				@ar rcs ${NAME} ${OBJECTS}
				@printf "\033[92mft_printf compiled\n\033[0m"

debug		:
				@make
				clang main.c libftprintf.a -I include -I libft
				./a.out

clean:
				@make -C libft clean
				@rm -rf ${OBJECTS}
				@printf "\033[92mclean done\n\033[0m"

fclean:			clean
				@make -C libft fclean
				@rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
