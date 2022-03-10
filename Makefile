SRC = parsing.c test.c split.c lis.c lismore.c

NAME = push_swap

CC = gcc 

COMMAND = @cd command && make

LIBFT = @cd LIBFT && make

FTPRINTF = @cd ft_printf && make

HEADER = push_swap.h

FLAGS	= -Wall -Wextra -Werror 

OBJ = ${SRC:.c=.o}


RM = rm -f

all	: ${NAME}

${NAME} : 	${OBJ}
		${LIBFT}
		${COMMAND}
		${FTPRINTF}
		${CC} ${FLAGS} -o ${NAME} ${OBJ} command/command.a LIBFT/libft.a ft_printf/libftprintf.a

clean :
	${RM} ${OBJ}
	@cd LIBFT && make clean
	@cd ft_printf && make clean
	@cd command && make clean

fclean :	clean
	${RM} ${NAME}
	@cd LIBFT && make fclean
	@cd ft_printf && make fclean
	@cd command && make fclean

re :	fclean all
