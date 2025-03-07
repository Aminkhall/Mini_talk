NAME_Client 	=	client
NAME_Server 	=	server

NAME_Client_Bonus 	=	client_bonus
NAME_Server_Bonus 	=	server_bonus
CC 		=	cc

HEADER 	=	mini_talk.h
HEADER_BONUS 	=	mini_talk_bonus.h

CFLAGS 	= 	-Wall -Wextra -Werror

Client 	=	client.c \
			utils.c \
			utils2.c \

Server	=	server.c \
			utils.c \

Client_Bonus 	=	client_bonus.c \
					utils3_bonus.c \
					utils2_bonus.c \

Server_Bonus	=	server_bonus.c \
					utils_bonus.c \
					utils2_bonus.c \

OClient 	= 	${Client:.c=.o}
OServer		=	${Server:.c=.o}

OClient_Bonus 	= 	${Client_Bonus:.c=.o}
OServer_Bonus	=	${Server_Bonus:.c=.o}

all: ${NAME_Client} $(NAME_Server)

bonus: ${NAME_Client_Bonus} ${NAME_Server_Bonus}

${NAME_Client} : ${OClient}
	@ ${CC} ${CFLAGS} ${OClient} -o ${NAME_Client}

${NAME_Server} : ${OServer}
	@ ${CC} ${CFLAGS} ${OServer} -o ${NAME_Server}

${NAME_Client_Bonus} : ${OClient_Bonus}
	@ ${CC} ${CFLAGS} ${OClient_Bonus} -o ${NAME_Client_Bonus}

${NAME_Server_Bonus} : ${OServer_Bonus}
	@ ${CC} ${CFLAGS} ${OServer_Bonus} -o ${NAME_Server_Bonus}


%.o : %.c $(HEADER)
	@ ${CC} ${CFLAGS} -c $< -o $@

%bonus.o : %bonus.c $(HEADER_BONUS)
	@ ${CC} ${CFLAGS} -c $< -o $@
	
clean :
	@rm -f ${OClient}
	@rm -f ${OServer}
	@rm -f ${OClient_Bonus}
	@rm -f ${OServer_Bonus}

re: fclean all

fclean : clean
	@rm -f ${NAME_Client}
	@rm -f ${NAME_Server}
	@rm -f ${NAME_Client_Bonus}
	@rm -f ${NAME_Server_Bonus}
	
.PHONY: all clean fclean re