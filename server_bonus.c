/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:41:14 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/30 19:27:56 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr_handler(int sig, siginfo_t *info, void *context)
{
	static int	i;
	static int	c;
	char		cp;

	(void) context;
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
		if (c == '\0')
			kill(info -> si_pid, SIGUSR1);
	}
	i--;
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = &sigusr_handler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
