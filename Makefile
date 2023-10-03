# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yususato <yususato@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 16:12:07 by yususato          #+#    #+#              #
#    Updated: 2023/09/25 22:31:32 by yususato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(SERVER) $(CLIENT)

CLIENT = client

SERVER = server

SERVER_SRCS = server.c ft_printf.c printf_tool.c ft_printf_uni.c

CLIENT_SRCS = client.c ft_atoi.c  ft_printf.c printf_tool.c ft_printf_uni.c

 INCL = includes

CC = cc

CFLAG = -Wall -Wextra -Werror

SRCS = server.c \
		client.c \
		ft_printf.c \
		ft_atoi.c \
		ft_print_uni.c \
		printf_tool.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all : $(NAME)

# $(NAME): $(SERVER_OBJS) $(CLIENT_OBJS)
# 	ar rcs $(NAME) $(SERVER_OBJS) $(CLIENT_OBJS)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS)

clean : 
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean : clean 
	$(RM) $(SERVER) $(CLIENT)

re : fclean all
