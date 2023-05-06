# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 17:03:14 by nbordoni          #+#    #+#              #
#    Updated: 2023/02/14 14:31:22 by nbordoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
####### NAME #########

NAMES = server 
NAMEC = client
BONUS = server_bonus
BONUC = client_bonus

###### VARIABLE ######

INCLUDE = include

DIRSRCS =
DIROBJS = obj/

FLSRCS = ft_printf.c

FLOBJS = ${FLSRCS:.c=.o}
OBJS = $(addprefix $(DIROBJS),$(FLOBJS))

CLISRC = client.c
CLISRC2 = client_bonus.c
SRVSRC = server.c
SRVSRC2 = server_bonus.c

CLIOBJ = ${CLISRC:.c=.o}
CLIOBJ2 = ${CLISRC2:.c=.o}
SRVOBJ = ${SRVSRC:.c=.o}
SRVOBJ2 = ${SRVSRC2:.c=.o}

COBJS = $(addprefix $(DIROBJS),$(CLIOBJ))
COBJS2 = $(addprefix $(DIROBJS),$(CLIOBJ2))
SOBJS = $(addprefix $(DIROBJS),$(SRVOBJ))
SOBJS2 = $(addprefix $(DIROBJS),$(SRVOBJ2))

CC = cc
AR = ar
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

###### COLORS ########

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

######## EXT #########

# make a .o file using a .c file
# $< for the .c file
# $@ for the .o file

# .inextention.outextention:

#.c.o:
$(DIROBJS)%.o: $(DIRSRCS)%.c
	@echo "$(YELLOW)Compiling:$(BLUE) $< $(DEF_COLOR)"
	@${CC} ${CFLAGS} -I ${INCLUDE} -c $< -o $@

####### RULES ########

all: ${NAMES} ${NAMEC}

${NAMEC}: ${OBJS} ${COBJS}
	@echo "$(YELLOW)Program created with $(WHITE)${CC}$(YELLOW) as $(CYAN)${NAMEC}$(DEF_COLOR)"
	@${CC} ${CFLAGS} -I ${INCLUDE} -o $(NAMEC) ${COBJS} $(OBJS)

${NAMES}: ${OBJS} ${SOBJS}
	@echo "$(YELLOW)Program created with $(WHITE)${CC}$(YELLOW) as $(CYAN)${NAMES}$(DEF_COLOR)"
	@${CC} ${CFLAGS} -I ${INCLUDE} -o $(NAMES) ${SOBJS} $(OBJS)

bonus:	${BONUS} ${BONUC}

${BONUC}: ${OBJS} ${COBJS2}
	@echo "$(YELLOW)Program created with $(WHITE)${CC}$(YELLOW) as $(CYAN)${BONUC}$(DEF_COLOR)"
	@${CC} ${CFLAGS} -I ${INCLUDE} -o $(BONUC) ${COBJS2} $(OBJS)

${BONUS}: ${OBJS} ${SOBJS2}
	@echo "$(YELLOW)Program created with $(WHITE)${CC}$(YELLOW) as $(CYAN)${BONUS}$(DEF_COLOR)"
	@${CC} ${CFLAGS} -I ${INCLUDE} -o $(BONUS) ${SOBJS2} $(OBJS)

clean:
	${RM} ${OBJS} ${COBJS} ${SOBJS} ${SOBJS2} ${COBJS2}

fclean: clean
	${RM} ${NAMEC} ${NAMES} ${BONUC} ${BONUS}

re: fclean all

reb: fclean bonus

.PHONY: all clean fclean re bonus .c.o
.SUFFIXES: .c .o
