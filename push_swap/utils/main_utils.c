/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:03:09 by alperrot          #+#    #+#             */
/*   Updated: 2024/04/24 16:24:47 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	has_space(char *str)
{
	while (*str)
	{
		if (is_space(*str))
			return (1);
		str++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		n;
	int		neg;

	i = 0;
	n = 0;
	neg = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - 48);
		i++;
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
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				j++;
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
			{
				if (!is_space(av[i][j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
