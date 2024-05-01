# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 10:58:12 by sbakhit           #+#    #+#              #
#    Updated: 2024/05/01 14:30:08 by sbakhit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus
NAME = $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

all: $(NAME)

$(NAME_SERVER): $(LIBFT) $(FT_PRINTF) server.c
	$(CC) $(CFLAGS) server.c $(LIBFT) $(FT_PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(LIBFT) $(FT_PRINTF) client.c
	$(CC) $(CFLAGS) client.c $(LIBFT) $(FT_PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER_BONUS): $(LIBFT) $(FT_PRINTF) server_bonus.c
	$(CC) $(CFLAGS) server_bonus.c $(LIBFT) $(FT_PRINTF) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(LIBFT) $(FT_PRINTF) client_bonus.c
	$(CC) $(CFLAGS) client_bonus.c $(LIBFT) $(FT_PRINTF) -o $(NAME_CLIENT_BONUS)

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C ft_printf

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -f $(NAME)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf

re : fclean all

.PHONY: clean fclean all bonus re
