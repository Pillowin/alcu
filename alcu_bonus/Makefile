S			=	src/
I			=	header/
O			=	obj/
D			=	dep/

NAME		=	alcu_bonus

SRC			=	$(wildcard $S*.c)

OBJ			=	$(SRC:$S%.c=$O%.o)
DEP			=	$(SRC:$S%.c=$D%.d)

MLX 		=	minilibx-linux/

CC			=	cc

CFLAGS		+=	-I$I
CFLAGS		+=	-I$(MLX)
CFLAGS		+=	-Wall -Wextra -Werror

LDFLAGS		+=	-L$(MLX)

LIBS		= -lm -lmlx -lXext -lX11

RM			=	/bin/rm -f
RMDIR		=	/bin/rm -Rf

.PHONY: all clean fclean minilibx re

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

minilibx:
	make -C $(MLX)

$(NAME): minilibx $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@ $(LIBS)

clean:
	make -C $(MLX) clean
	$(RMDIR) $(wildcard $(NAME).dSYM)
	$(RMDIR) $O
	$(RM) $(wildcard $(DEP))
	$(RMDIR) $D

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE)

-include $(DEP)
