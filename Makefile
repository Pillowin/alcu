# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agautier <agautier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 21:24:39 by agautier          #+#    #+#              #
#    Updated: 2022/02/11 21:30:01 by agautier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S			=	src/
I			=	header/
O			=	obj/
D			=	dep/

NAME		=	alcu

SRC			=	$(wildcard $S/*.c)

OBJ			=	$(SRC:$S%.c=$O%.o)
DEP			=	$(SRC:$S%.c=$D%.d)

CC			=	cc

CFLAGS		+=	-I$I
CFLAGS		+=	-Wall -Wextra -Werror

RM			=	/bin/rm -f
RMDIR		=	/bin/rm -Rf

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir -p $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$D:
	@mkdir -p $@

$(DEP): | $D

$(DEP): $D%.d: $S%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

clean:
	$(RMDIR) $(wildcard $(NAME).dSYM)
	$(RMDIR) $O
	$(RM) $(wildcard $(DEP))
	$(RMDIR) $D

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

-include $(DEP)
