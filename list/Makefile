NAME			:=	list

SRC				:=	main.c\
						input.c\
						list.c\
						list_delete.c\
						output.c\
						parser.c

OBJ				:=	$(SRC:.c=.o)
HEADERS			:=	libmp.h list.h
LIB				:=	libmp.a

DIR_SRC			:=	./src/
DIR_LIB			:=	../lib/
DIR_OBJ			:=	./obj/
DIR_INCLUDE_LIB	:=	../lib/
DIR_INCLUDE		:=	./include/
DIR_INCLUDES	:=	$(DIR_INCLUDE_LIB) $(DIR_INCLUDE)

CC				:=	gcc
CFLAGS			:=	-Wall -Wextra -Werror -g

REMOVE_DIR		:=	rm -rf
REMOVE_FILE		:=	rm -rf

OBJ_WITH_PATH	:=	$(addprefix $(DIR_OBJ), $(OBJ))
LIB_WITH_PATH	:=	$(DIR_LIB)$(LIB)
INCLUDES		:= $(addprefix -I , $(DIR_INCLUDE) $(DIR_INCLUDE_LIB))

vpath		%.c $(DIR_SRC)
vpath		%.o $(DIR_OBJ)
vpath		%.h $(DIR_INCLUDES)
vpath		%.a $(DIR_LIB)

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ_WITH_PATH) $(INCLUDES) -o $@ $(LIB_WITH_PATH)

$(OBJ):%.o:%.c $(HEADERS) | $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $(DIR_OBJ)$@ $(INCLUDES) -pipe

$(DIR_OBJ):
	mkdir -p $@

$(LIB):
	make -C ../lib

clean:
	$(REMOVE_DIR) $(DIR_OBJ)

fclean:
	$(REMOVE_FILE)

re: clean fclean all

.SILENT: all $(NAME) $(OBJ) $(DIR_OBJ) $(LIB) clean fclean re
