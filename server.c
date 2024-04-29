/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:57:58 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/29 21:27:09 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void sigusr_handler(int sig)
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
		write(1, &cp, 1);
	}
	i--;
}
 
int	main(void)
{
	struct sigaction sa;
	int pid = getpid();

	sa.sa_handler = &sigusr_handler;
	sa.sa_flags = SA_SIGINFO;
	printf("PID: %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}