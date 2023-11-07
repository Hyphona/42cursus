/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:33:56 by alperrot          #+#    #+#             */
/*   Updated: 2023/09/03 20:09:48 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	*ft_init_dict(char *dict_name);
int		ft_atoi(char *argv);
int		ft_is_numeric(char c);
int		ft_strlen(char *str);
void	solve(int nbr, char *dict, int len);

int	ft_arg_is_valid(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_is_numeric(argv[i]))
		{
			i++;
			continue ;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	*dict;

	if (argc <= 1)
		write(1, "Error: No arguments\n", 20);
	else if (argc == 2)
	{
		if (ft_arg_is_valid(argv[1]))
		{
			dict = ft_init_dict("numbers.dict");
			if (dict[0] == '\0')
				write(1, "Dict Error\n", 11);
			solve(ft_atoi(argv[1]), dict, ft_strlen(argv[1]));
		}
	}
	else if (argc >= 3)
	{
		if (ft_arg_is_valid(argv[2]))
		{
			dict = ft_init_dict(argv[1]);
			if (dict[0] == '\0')
				write(1, "Dict Error\n", 11);
			solve(ft_atoi(argv[2]), dict, ft_strlen(argv[2]));
		}
	}
}
