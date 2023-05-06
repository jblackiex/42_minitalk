/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbordoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:25:13 by nbordoni          #+#    #+#             */
/*   Updated: 2023/02/14 14:25:16 by nbordoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	send_char(int pid, char octet)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (octet & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = atoi(av[1]);
		while (av[2][i])
		{
			send_char(pid, av[2][i]);
			i++;
		}
		send_char(pid, '\n');
	}
	else
	{
		ft_printf("\033[91mError: wrong format mammelucco\033[0m\n");
		ft_printf("\033[33mTry: ./client <PID> <MESSAGE_TO_SEND>\033[0m\n");
		return (1);
	}
	return (0);
}
