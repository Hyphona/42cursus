/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:14:31 by alperrot          #+#    #+#             */
/*   Updated: 2023/08/20 21:01:21 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);
void	rush(int x, int y);
int		ft_putstr(char *str);
int		ft_char_to_int(char *argv, int size);
int		str_comp(int size, char *str, char *max_int);
int		ft_analyze(char *argv1, char *argv2);

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc == 3)
	{
		if (argv[1][0] == '-' || (argv[2][0] == '-'))
			return (0);
		while (i < 3)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				if ((argv[i][j] < '0' || argv[i][j] > '9'))
					return (0);
				j++;
			}
		i++;
		}
		ft_analyze(argv[1], argv[2]);
	}
	return (0);
}

int	ft_analyze(char *argv1, char *argv2)
{
	int	size_x;
	int	size_y;
	int	x;
	int	y;

	size_x = ft_putstr(argv1);
	size_y = ft_putstr(argv2);
	x = 0;
	y = 0;
	if (ft_char_to_int(argv1, size_x) == 0
		|| ft_char_to_int(argv2, size_y) == 0)
		return (0);
	else
	{
		x = ft_char_to_int(argv1, size_x);
		y = ft_char_to_int(argv2, size_y);
	}
	rush(x, y);
	return (0);
}

int	str_comp(int size, char *str, char *max_int)
{	
	int	i;

	i = 0;
	while (i < size)
	{
		if ((str[i] - max_int[i]) > 0)
			if (str[i] > max_int[i])
				return (0);
		i++;
	}
	return (0);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_char_to_int(char *argv, int size)
{
	int	x;
	int	i;
	int	z;

	x = 0;
	z = 1;
	i = 0;
	if (argv[i] == '0')
		return (0);
	if (size > 10)
		return (0);
	else if (size == 10)
	{
		if (str_comp(size, argv, "2147483647") == 0)
			return (0);
	}
	while (size > 0)
	{
		x = x + z * (argv[size - 1] - 48);
		z = 10 * z;
		size--;
	}
	return (x);
}
