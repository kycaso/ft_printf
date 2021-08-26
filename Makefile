# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelda-h <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 18:24:51 by fbelda-h          #+#    #+#              #
#    Updated: 2021/07/08 23:37:46 by fbelda-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#creamos las variables, son solo nombres no tienen sentido hasta que se compila algo con ellos
CC= cc
CFLAGS= -o3 -Wall -Werror -Wextra -g
SRCS= ft_printf.c aux1.c aux2.c aux3.c
OBJ= $(SRCS:.c=.o)
SRCS_BONUS= ft_printf_bonus.c aux1_bonus.c aux2_bonus.c aux3_bonus.c
OBJ= $(SRCS:.c=.o)
OBJ_BONUS=$(SRCS_BONUS:.c=.o)
LIBFT= libft
INCL_BONUS= libftprintf_bonus.c
INCL= libftprintf.h
NAME= libftprintf.a
## regla patrón . genera archivos.o a partir de los .c
## $* variables automáticas $@sustituye al target y $< sustituye al source file

%.o:%.c $(INCL)
	$(CC) -c $(CFLAGS) $< -o $@
%.o:%.c $(INCL_BONUS)
	$(CC) -c $(CFLAGS) $< -o $@
$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT)
	ar rcs $(NAME) $(OBJ) $(LIBFT)/*.o
.PHONY : clean fclean norma all re bonus
all: $(NAME)

clean:
	rm -f $(NAME) 
fclean:
	@$(MAKE) fclean -C $(LIBFT)
	rm -f $(NAME) $(OBJ) $(OBJ_BONUS)
norma:
	norminette $(SRCS)
re: fclean all
bonus: $(NAME) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

