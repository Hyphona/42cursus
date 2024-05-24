/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:35:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/24 10:29:50 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	handshake;

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
	int				time;
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
		handshake = 0;
		time = 0;
		while (handshake == 0)
		{
			usleep(100);
			if (time >= 500)
				break ;
			time += 100;
		}
	}
}

static void	handler(int signum)
{
	(void)signum;
	handshake = 1;
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
	if (kill(pid, 0) == 0 && pid > 0)
	{
		i = 0;
		signal(SIGUSR1, handler);
		while (av[2][i])
		{
			send_bit(pid, av[2][i]);
			i++;
		}
		send_bit(pid, '\0');
	}
	else
		ft_printf("PID is not valid\nUsage: %s <PID> <message>\n", av[0]);
	return (0);
}
