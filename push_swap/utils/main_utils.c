/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:03:09 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/19 12:14:47 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_hasspace(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			return (1);
		str++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		n;
	int		neg;

	n = 0;
	neg = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = (n * 10) + (*str - 48);
		str++;
	}
	return (n * neg);
}

int	check_args(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				if (av[i][j] != ' ' && !ft_isspace(av[i][j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
