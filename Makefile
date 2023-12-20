CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= battleship-kreator

SRC		= src/main.c \
		  src/libft.c \
		  src/ships.c

INCDIR	= inc/

all: NAME

NAME:
	$(CC) $(CFLAGS) -I $(INCDIR) $(SRC) -o $(NAME)
