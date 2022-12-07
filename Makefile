# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcabrero <rcabrero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 20:47:07 by rcabrero          #+#    #+#              #
#    Updated: 2022/12/07 12:47:14 by rcabrero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
SRCS    =  	ft_printf.c ft_printf_hexadecimal.c ft_printf_number.c \
            ft_itoa.c ft_putchar_fd.c ft_printf_pointer.c

OBJS        = ${SRCS:.c=.o}
RM          = rm -f
LIB         = ar rc
CC          = gcc
FLAGS		= -Wall -Werror -Wextra
.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I.
${NAME}:    ${OBJS}
			${LIB} ${NAME} ${OBJS}
all:		${NAME}
clean:
			${RM} ${OBJS} 
fclean:		clean
			${RM} ${NAME}
re:			fclean all
rebonus:	fclean bonus
.PHONY:		bonus all clean fclean re rebonus