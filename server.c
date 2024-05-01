/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:57:58 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/30 22:57:47 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr_handler(int sig)
{
	static int	i;
	static int	c;
	char		cp;

	if (!i)
	{
		i = 8;
		c = 0;
	}
	if (sig == SIGUSR2)
		c = c | 1 << (i - 1);
	if (i == 1)
	{
		cp = c + 0;
		ft_printf("%c", cp);
		if (!cp)
			ft_printf("\n");
	}
	i--;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &sigusr_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
