/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:42:14 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/30 22:00:32 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	recieve_handler(int sig)
{
	if (sig)
		ft_printf("recieved\n");
}

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
			ft_printf("Error!\n");
			exit(1);
		}
		usleep(500);
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
	struct sigaction	sa1;

	i = 0;
	sa1.sa_handler = &recieve_handler;
	sigaction(SIGUSR1, &sa1, NULL);
	if (ac != 3)
	{
		ft_printf("Error! Less or More than 3 Args\n");
		exit(EXIT_FAILURE);
	}
	if (check(av[1]) || ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > INT_MAX)
	{
		ft_printf("Error! Unacceptable PID\n");
		exit(EXIT_FAILURE);
	}
	while (av[2][i])
		send_signal(ft_atoi(av[1]), av[2][i++]);
	send_signal (ft_atoi(av[1]), '\0');
}
