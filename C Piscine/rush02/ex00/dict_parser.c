/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmagere <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 17:19:50 by bmagere           #+#    #+#             */
/*   Updated: 2023/09/03 18:07:00 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *dict);
int	ft_is_numeric(char c);
int	ft_is_space(char c);
int	ft_is_printable(char c);

char	*ft_copy_dict(char *temp)
{
	char	*dest;
	int		i;
	int		n;
	int		j;

	n = ft_strlen(temp);
	dest = malloc(n + 1);
	i = 0;
	j = 0;
	while (i <= n)
	{
		while (temp[i] == '\n' && temp[i + 1] == '\n')
			i++;
		dest[j] = temp[i];
		j++;
		i++;
	}
	free(temp);
	dest[j] = '\0';
	return (dest);
}

void	ft_remove_space(char *dict, char *temp, int *i, int *j)
{
	while (dict[i[0]] != '\n')
	{
		if (dict[i[0]] == ':' || ft_is_printable(dict[i[0]]))
			break ;
		i[0]++;
	}
	if (dict[i[0]] == ':' && dict[i[0] + 1] == ' ')
	{
		i[0]++;
		while (ft_is_space(dict[i[0]]))
			i[0]++;
		temp[j[0]] = '\n';
		j[0]++;
	}
	else if (dict[i[0]] == ':' || dict[i[0]] == '\n')
		temp[j[0]] = dict[i[0]];
	else
	{
		temp[j[0]] = ' ';
		j[0]++;
		temp[j[0]] = dict[i[0]];
	}
}

char	*ft_fix_dict(char *dict)
{
	int		*i;
	int		*j;
	char	*temp;

	i = malloc(sizeof(int));
	i[0] = 0;
	j = malloc(sizeof(int));
	j[0] = 0;
	temp = malloc(ft_strlen(dict) + 1);
	while (dict[i[0]])
	{
		if ((ft_is_space(dict[i[0]]) && ft_is_space(dict[i[0] + 1]))
			|| (ft_is_space(dict[i[0]]) && dict[i[0] + 1] == ':')
			|| (ft_is_space(dict[i[0]]) && dict[i[0] + 1] == '\n')
			|| (ft_is_space(dict[i[0] + 1]) && dict[i[0]] == ':'))
		{
			ft_remove_space(dict, temp, i, j);
		}
		temp[j[0]] = dict[i[0]];
		i[0]++;
		j[0]++;
	}
	temp[j[0] + 1] = '\0';
	free(dict);
	return (ft_copy_dict(temp));
}
