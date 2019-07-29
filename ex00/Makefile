# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sengle <sengle@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/25 15:28:50 by sengle            #+#    #+#              #
#    Updated: 2019/07/28 18:01:33 by sjiseong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM = colle-2
SRCS = src/main.c src/parse_rush.c src/check_rush.c src/print_rush.c\
#		src/do_math.c src/ft_atoi.c src/ft_putstr.c src/ft_strcmp.c
INCDIR = include
OBJECTS = main.o parse_rush.o check_rush.o print_rush.o
#			src/do_math.c ft_atoi.o ft_putstr.o ft_strcmp.o 
CFLAGS = -g -Wall -Werror -Wextra -I $(INCDIR)

all:		$(PROGRAM)

$(PROGRAM):	$(SRCS)
			gcc $(CFLAGS) -o $(PROGRAM) $(SRCS)

clean:
			rm -rf *.o

fclean: 	clean
			rm -f $(PROGRAM)

re: 		fclean all
