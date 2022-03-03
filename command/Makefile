SRC = push.c reverse_rotate.c rotate.c swap.c 

CC = gcc

HEADER = command.h

OBJ = $(SRC:.c=.o)


NAME = command.a

RM = rm -f

LIBC = ar -rc

CFLAGS	= -Wall -Wextra -Werror

%.o : %.c
	$(CC) ${CFLAGS} -I. -o $@ -c $?

${NAME} : $(OBJ)
	${LIBC} ${NAME} ${OBJ}


all :	${NAME} 

clean :
	${RM} ${OBJ} 

fclean :	clean
	${RM} ${NAME}

re :	fclean all
