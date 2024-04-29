/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:57:49 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/29 21:26:35 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static void	send_signal(int pid, char c)
{
	int	i;
	int	return_kill;

	i = 8;
	while (i--)
	{
		if (c & 1 << i)
			return_kill = kill(pid, SIGUSR2);
		else
			return_kill = kill(pid, SIGUSR1);
		if (return_kill == -1)
		{
			write(1, "wrong pid", 9);
			exit(1);
		}
		usleep(350);
	}
}

static int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int					i;

	i = 0;
	if (ac == 3)
	{
		if (check(av[1]) || ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > INT_MAX)
		{
			write(1, "WRONG PID\n", 10);
			exit(EXIT_FAILURE);
		}
		while (av[2][i])
		{
			send_signal(atoi(av[1]), av[2][i]);
			i++;
		}
		send_signal (atoi(av[1]), '\0');
	}
	else
		write(2, "not 2 arguements\n", 18);
	return (1);
}

// void send_signal(int pid, char *str)
// {
// 	int i;
// 	int	bits_counter;
// 	int	bit;

// 	i = 0;
// 	while (str && str[i] && bits_counter--)
// 	{
// 		bits_counter = 0;
// 		while (bits_counter < 8)
// 		{
// 			bit = ((str[i] >> bits_counter) & 1);
// 			if (bit % 2 == 0)
// 				kill(pid, SIGUSR2);
// 			else
// 				kill(pid, SIGUSR1);
// 			usleep(42);
// 			bits_counter++;
// 		}
// 		i++;
// 	}
// }
// int	main(int ac, char **av)
// {
// 	int		pid;
// 	char	*str;
	
// 	if (ac == 3)
// 	{
// 		pid = ft_atoi(av[1]);
// 		if (!(ft_isdigit(pid)) && pid <= 0)
// 			write(1, "Wrong PID\n", 10);
// 		str = av[2];
// 		send_signal(pid, str);
// 	}
// 	else
// 	{
// 		printf("Error\n");
// 		exit(EXIT_FAILURE);
// 	}
// }