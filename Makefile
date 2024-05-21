##
## EPITECH PROJECT, 2023
## test
## File description:
## test
##

NAME =		secured

SRC =		hashtable.c		\
		delete_hashtable.c	\
		hashtable_dump.c	\
		insert.c		\
		linked_list.c		\
		search.c		\
		my_strlen.c		\
		my_strdup.c		\
		my_strcpy.c		\
		my_putstr.c		\
		my_put_nbr.c		\
		my_putchar.c		\

OBJ =		$(SRC:.c=.o)

CFLAGS =	-Wall -Wextra

CPPFLAGS =	-I ./include

LD_LIBRARY_PATH = -L./lib/my

LDFLAGS  =	-lmy			\

LIB_PATH =	./lib/my

all:    $(NAME)

$(NAME): $(OBJ)
	ar rc libhashtable.a $(OBJ)

test: $(NAME)
	$(MAKE) -C $(LIB_PATH)
	$(CC) -o test main.c -L. -lhashtable
	./test

clean:
	rm $(OBJ)
	rm libhashtable.a

fclean: clean

re: fclean all
