/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:35:55 by alperrot          #+#    #+#             */
/*   Updated: 2024/03/04 09:24:58 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static int	ft_atoi(const char *str)
{
	int		n;
	int		neg;

	n = 0;
	neg = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
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
		usleep(42);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		ft_printf("Usage: %s <PID> <string>\n", av[0]);
		return (1);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		send_bit(pid, av[2][i]);
		i++;
	}
	send_bit(pid, '\0');
	return (0);
}
