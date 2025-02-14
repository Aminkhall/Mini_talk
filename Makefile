NAME_Client 	=	client
NAME_Server 	=	server
CC 		=	cc

HEADER 	=	mini_talk.h

CFLAGS 	= 	-Wall -Wextra -Werror

Client 	=	client.c \
			utils.c \

Server	=	server.c \
			utils.c \

OClient 	= 	${Client:.c=.o}
OServer	=	${Server:.c=.o}

all: ${NAME_Client} $(NAME_Server)

${NAME_Client} : ${OClient}
	@ ${CC} ${CFLAGS} ${OClient} -o ${NAME_Client}

${NAME_Server} : ${OServer}
	@ ${CC} ${CFLAGS} ${OServer} -o ${NAME_Server}

%.o : %.c $(HEADER)
	@ ${CC} ${CFLAGS} -c $< -o $@
	
clean :
	@rm -f ${OClient}
	@rm -f ${OServer}

re: fclean all

fclean : clean
	@rm -f ${NAME_Client}
	@rm -f ${NAME_Server}
	
.PHONY: all clean fclean re