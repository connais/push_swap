SRC = parsing.c


NAME = push_swap


CC = gcc 

LIBFT = @cd LIBFT && make

FTPRINTF = @cd ft_printf && make

HEADER = push_swap.h

FLAGS	= -Wall -Wextra -Werror 

OBJ = ${SRC:.c=.o}


RM = rm -f

all	: ${NAME}

${NAME} : 	${OBJ}
		${LIBFT}
		${FTPRINTF}
		${CC} ${FLAGS} -o ${NAME} ${OBJ} LIBFT/libft.a ft_printf/libftprintf.a

clean :
	${RM} ${OBJ}
	@cd LIBFT && make clean
	@cd ft_printf && make clean


fclean :	clean
	${RM} ${NAME}
	@cd LIBFT && make fclean
	@cd ft_printf && make fclean

re :	fclean all
