NAME    = codexion
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

CFILES  = main.c
OFILES  = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OFILES)
