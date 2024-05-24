/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:36:03 by alperrot          #+#    #+#             */
/*   Updated: 2024/05/22 13:44:12 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

static char	*ft_strjoin(char *s1, char s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc((sizeof(char) * (ft_strlen(s1) + 1) + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		str[j++] = s1[i++];
	str[j++] = s2;
	str[j++] = '\0';
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (str);
}

static void	handler(int signum, siginfo_t *siginfo, void *context)
{
	static unsigned int		c;
	static int				bit;
	static char				*str;

	(void) context;
	c |= (signum == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (c)
			str = ft_strjoin(str, c);
		else
		{
			ft_printf("%s\n", str);
			free(str);
			kill(siginfo->si_pid, SIGUSR1);
			str = NULL;
		}
		bit = 0;
		c = 0;
	}
	else
		c <<= 1;
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	ft_printf("Server PID: %d\n", getpid());
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
	{
		ft_printf("Error SIGUSR1\n");
		return (0);
	}
	if (sigaction(SIGUSR2, &act, NULL) == -1)
	{
		ft_printf("Error SIGUSR2\n");
		return (0);
	}
	while (1)
		pause();
	return (0);
}
