NAME= fdf

SRCS= src/main.c\
	  src/parsing.c\
	  src/key_press.c\
	  src/data_man.c\
	  src/tracer.c\
	  src/rotate.c\
	  src/line.c\
	  src/clean.c\
	  src/protect.c\
	  src/ints.c\

OBJ= $(SRCS:.c=.o)

LIBDIR= libft

MINILIB = minilibx_macos

LIBA = $(LIBDIR)/libft.a

LIBA += $(MINILIB)/libmlx.a

CC = clang

CFLAGS= -Wall -Werror -Wextra

LFLAGS= -framework OpenGL -framework AppKit 

HEAD = includes/fdf.h

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	$(MAKE) -C $(MINILIB) &> /dev/null
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBA) $(LFLAGS) 
	@echo "fdf build complete"

$(LIBA): FORCE
	$(MAKE) -C $(LIBDIR)

FORCE:

$(OBJ): %.o : %.c $(HEAD)
	$(CC) -I $(LIBDIR) $(CFLAGS) -o $@ -c $<

clean:
		$(RM) -R $(OBJ)
		@echo "fdf objects cleaned"
		$(MAKE) clean -C $(LIBDIR)
		$(MAKE) clean -C $(MINILIB)

fclean: clean
		$(MAKE) fclean -s -C $(LIBDIR)
		$(RM) $(NAME)
		@echo "fdf project cleaned"

re: fclean all

.PHONY: all clean fclean re FORCE
