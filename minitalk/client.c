/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:35:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/24 20:34:04 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	g_handshake;

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

static void	handshake_handler(void)
{
	int			i;

	i = 0;
	while (g_handshake == 0)
	{
		usleep(100);
		if (i >= 70000)
		{
			ft_printf("Signal lost (Sending bit anyway)\n");
			break ;
		}
		i += 100;
	}
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
		g_handshake = 0;
		handshake_handler();
	}
}

static void	handler(int signum)
{
	(void)signum;
	g_handshake = 1;
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		ft_printf("Too much arguments, usage: %s <PID> <message>\n", av[0]);
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == 0 && pid > 0)
	{
		i = 0;
		g_handshake = 0;
		signal(SIGUSR1, handler);
		while (av[2][i])
		{
			send_bit(pid, av[2][i]);
			i++;
		}
		send_bit(pid, '\0');
	}
	else
		ft_printf("PID is not reachable\n", av[0]);
	return (0);
}
