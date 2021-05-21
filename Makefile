##
## EPITECH PROJECT, 2020
## infin_add
## File description:
## Makefile
##

NAME	=	my_rpg

SRCS := $(wildcard src/*.c)
SRCS += $(wildcard src/loading_menu/*.c)
SRCS += $(wildcard src/animations/*.c)
SRCS += $(wildcard src/boss/*.c)
SRCS += $(wildcard src/boat/*.c)
SRCS += $(wildcard src/custom/*.c)
SRCS += $(wildcard src/destroy/*.c)
SRCS += $(wildcard src/particles/*.c)
SRCS += $(wildcard src/cave/*.c)
SRCS += $(wildcard src/house/*.c)
SRCS += $(wildcard src/enemy/*.c)
SRCS += $(wildcard src/player/*.c)
SRCS += $(wildcard src/skills/*.c)
SRCS += $(wildcard src/inventory/*.c)
SRCS += $(wildcard src/save/*.c)
SRCS += $(wildcard src/menu/*.c)
SRCS += $(wildcard src/sound/*.c)
SRCS += $(wildcard src/quest/*.c)
SRCS += $(wildcard src/window/*.c)
SRCS += $(wildcard src/list/*.c)
SRCS += $(wildcard src/game/*.c)
SRCS += $(wildcard src/initialisation/*.c)

OBJS	=	$(SRCS:.c=.o)

NBR_OF_FILES := $(words $(SRCS))

CC = gcc #-g -fsanitize=address

RM	=	rm -f

INC = -I ./include/
INC += -I ./lib_short/include -L ./lib_short -lmy_short
INC += -I ./src/loading_menu/include/
INC += -I ./src/animations/include/
INC += -I ./src/boss/include/
INC += -I ./src/boat/include/
INC += -I ./src/custom/include/
INC += -I ./src/destroy/include/
INC += -I ./src/particles/include/
INC += -I ./src/cave/include/
INC += -I ./src/house/include/
INC += -I ./src/enemy/include/
INC += -I ./src/player/include/
INC += -I ./src/skills/include/
INC += -I ./src/inventory/include/
INC += -I ./src/save/include/
INC += -I ./src/menu/include/
INC += -I ./src/sound/include/
INC += -I ./src/quest/include/
INC += -I ./src/window/include/
INC += -I ./src/list/include/
INC += -I ./src/game/include/
INC += -I ./src/initialisation/include/

CFLAGS += $(INC)
CFLAGS += -l csfml-graphics -l csfml-system -l csfml-audio
CFLAGS += -W -Wall -Wextra -Wno-unused-parameter

TARGET_TEST	= $(wildcard ./lib_short/lib/my/*.c)

SRC_TEST	= $(wildcard tests/tests_lib/*.c)

all:	liblist	$(NAME)

liblist:
	make -C ./lib_short/

$(NAME): $(OBJS)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;36m$(NBR_OF_FILES)\033[0m"
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm
	@ echo "\033[1;35mBinary : \033[1;36m$(NAME)\033[1;35m created sucesfully.\033[0m"

tests_run:
	make -C ./lib_short
	$(CC) $(CFLAGS) -o test $(SRC_TEST) $(TARGET_TEST) $(INC) $(LIB_SHORT) --coverage -lcriterion
	./test

clean:
	@ echo "\033[3;31mRemoving: \033[0m"
	@ echo "\033[3;31m$(OBJS)\033[0m" | tr ' ' '\n'
	@ $(RM) $(OBJS)
	rm -f $(OBJLIST)
	make clean -C ./lib_short/

fclean:	clean
	@ echo "\033[3;31m./$(NAME)\033[0m"
	@ $(RM) $(NAME)
	rm -f lib/$(LIBLIST)
	rm -f include/list.h
	make fclean -C ./lib_short/
	rm -f *.gcno
	rm -f *.gcda
	rm -f test

re: 	fclean all

%.o:	%.c
	@ echo "\033[1;35m[ OK ]\033[0m Compiling" $<
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re