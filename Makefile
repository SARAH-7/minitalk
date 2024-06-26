# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 10:58:12 by sbakhit           #+#    #+#              #
#    Updated: 2024/05/01 14:43:04 by sbakhit          ###   ########.fr        #
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


$(NAME_SERVER): $(FT_PRINTF) $(LIBFT) server.c
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_CLIENT): $(FT_PRINTF) $(LIBFT) client.c
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(FT_PRINTF) $(LIBFT) server_bonus.c
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_CLIENT_BONUS): $(FT_PRINTF) $(LIBFT) client_bonus.c
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	make  all -C libft
$(FT_PRINTF):
	make  all -C ft_printf

clean:
	make clean -C libft
	make clean -C ft_printf

fclean:
	make fclean -C libft
	make fclean -C ft_printf
	rm -f server
	rm -f client
	rm -f server_bonus
	rm -f client_bonus

re : fclean all

.PHONY: bonus