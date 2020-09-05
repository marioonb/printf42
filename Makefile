# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 16:13:06 by mbelorge          #+#    #+#              #
#    Updated: 2020/01/29 15:55:13 by mbelorge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = libftprintf.c ft_flag.c ft_conversioncsp.c ft_conversiondiux.c ft_positiondiux.c ft_positionstrptr.c
OBJS = $(SRCS:.c=.o)
LIB_OBJS = ./libft/*.o
INCLUDES = ./includes/ft_printf.h
LIB = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g3
LOGFILE=$(LOGPATH) `date +'%y.%m.%d %H:%M:%S'`
all : $(NAME)

.c.o : $(SRCS)
	@(gcc -c $(CFLAGS) -I $(INCLUDES) $^ -o $(^:.c=.o))

$(NAME) : $(OBJS)
	@(make -C libft)
	@(ar rcs $(NAME) $(OBJS) $(LIB_OBJS))
	@(echo "ft_printf compiled")

ex : $(NAME)
	@(gcc $(CFLAGS) $(NAME) srcs/main.c -I $(INCLUDES))
	@(./a.out)

clean :
	@(rm -f $(OBJS))
	@(make clean -C libft)
	@(echo "ft_printf cleaned")

cleanlib :
	@(make fclean -C libft)

fclean : cleanlib clean
	@(rm -rf $(NAME))
	@(rm -f libft.a)
	@(rm -rf a.out.dSYM)
	@(rm -f a.out)
	@(echo "ft_printf full cleaned")

re : fclean all
