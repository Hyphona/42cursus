/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:35:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/03/06 09:37:56 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *str)
{
	int		n;
	int		neg;

	n = 0;
	neg = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while ((*str >= '0' && *str <= '9'))
	{
		n = (n * 10) + (*str - 48);
		str++;
	}
	return (n * neg);
}

static void	send_bit(int pid, unsigned char c)
{
	int				i;
	unsigned char	tmp;

	i = 8;
	tmp = c;
	while (i > 0)
	{
		i--;
		tmp = c >> i;
		if (tmp % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
	}
}

static void	handler(int signum)
{
	if (signum != SIGUSR1)
		exit(1);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", av[0]);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid)
	{
		i = 0;
		signal(SIGUSR1, handler);
		while (av[2][i])
		{
			send_bit(pid, av[2][i]);
			i++;
		}
		send_bit(pid, '\n');
	}
	else
		ft_printf("PID is not valid\nUsage: %s <PID> <message>\n", av[0]);
	return (0);
}
