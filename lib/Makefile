#THIS MAKEFILE FOR LINUX
NAME			:=	libmp.a
SRC				:=	mp_clean_stream.c\
						mp_errors.c\
						mp_putstr_fd.c\
						mp_validated_input.c\
						mp_write.c\
						mp_alloc.c

OBJ				:=	$(SRC:.c=.o)
HEADERS			:=	libmp.h

DIR_OBJ			:=	obj
OBJ_WITH_PATH	:=	$(addprefix $(DIR_OBJ)/, $(OBJ))

CFLAGS			:=	-Wall -Wextra -Werror
CC				:=	gcc

vpath	%.o	$(DIR_OBJ)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcus $@ $(OBJ_WITH_PATH)

$(OBJ): %.o:%.c $(HEADERS) | $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $(DIR_OBJ)/$@ -pipe

$(DIR_OBJ):
	mkdir -p $@

clean:
	rm -rf $(DIR_OBJ)

fclean:
	rm -rf $(NAME)

re: fclean all

.SILENT: all $(NAME) $(OBJ) $(DIR_OBJ) clean fclean re
