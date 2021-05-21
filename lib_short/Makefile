##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC	= gcc

SRC	= $(wildcard ./lib/my*.c)

OBJ	= $(SRC:.c=.o)

INC 	= -I ./include

FLAGS	= -W -Wall -Wextra

TARGET_TEST	= $(wildcard ./lib/my/tests/*.c)

SRC_TEST	= $(wildcard ./lib/my/*.c)

all: $(OBJ)
	@ $(CC) -c ./lib/my/*.c -I ./include/
	@ $(AR) rsc libmy_short.a *.o

tests_run: clean_test all
	@ $(CC) $(FLAGS) -o test $(SRC_TEST) $(TARGET_TEST) $(INC) -L . -lmy_short --coverage -lcriterion
	@ ./test

clean_test:
	@ $(RM) *.gcno
	@ $(RM) *.gcda
	@ $(RM) ./lib/my/*.gcno
	@ $(RM) ./lib/my/*.gcda

clean:
	@ $(RM) *~
	@ $(RM) #*#
	@ $(RM) *.o

fclean: clean clean_test
	@ $(RM) test
	@ $(RM) libmy_short.a

re: fclean all
