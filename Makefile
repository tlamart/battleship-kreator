CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= battleship-kreator

SRC		= src/main.c

INCDIR	= inc/

all: NAME

NAME:
	$(CC) $(CFLAGS) -I $(INCDIR) $(SRC) -o $(NAME)
