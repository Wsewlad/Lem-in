# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfil <vfil@student.unit.ua>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 17:18:58 by vfil              #+#    #+#              #
#    Updated: 2018/03/13 17:18:59 by vfil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in
SRC		=	main.c parse.c checker.c print_res.c find_road.c lists_manipulations.c \
			find_best_roads.c conductor.c print_bonus.c
FLAGS	=	-Wall -Wextra -Werror
MYLIB	=	-L libft -lftprintf -I libft

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(SRC)
	make -C libft/
	gcc -o $(NAME) $(FLAGS) $(SRC) $(MYLIB)

clean:
	@rm -f *.o
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re:
	make re -C libft/
	make fclean
	make all
