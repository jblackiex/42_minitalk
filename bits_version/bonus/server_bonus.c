/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:25:25 by nbordoni          #+#    #+#             */
/*   Updated: 2023/02/14 14:25:28 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	bit_handler(int signal, siginfo_t *info, void *s)
{
	static int	i;
	static int	bit;
	int			j;

	(void)s;
	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		j = i;
		i = 0;
		if (j == 10)
			kill(info->si_pid, SIGUSR2);
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sig;

	(void)av;
	if (ac != 1)
	{
		ft_printf("\033[91mError: wrong format.\033[0m\n");
		ft_printf("\033[33mTry: ./server\033[0m\n");
		return (1);
	}
	pid = getpid();
	ft_printf("\033[107m\033[34mProcess ID: %d\n\033[0m", pid);
	ft_printf("Waiting for a message...\n");
	sig.sa_sigaction = bit_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	while (ac == 1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}
