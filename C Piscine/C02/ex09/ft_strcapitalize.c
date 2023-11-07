/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:44:08 by alperrot          #+#    #+#             */
/*   Updated: 2023/08/23 10:01:30 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char str)
{
	if (str > 'Z' && str < 'a')
		return (0);
	else if (str > 'z' || str < 'A')
		return (0);
	return (1);
}

int	ft_str_is_numeric(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

int	ft_str_is_lowercase(char str)
{
	if (str >= 'a' && str <= 'z')
		return (1);
	return (0);
}

int	ft_str_is_uppercase(char str)
{
	if (str >= 'A' && str <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_str_is_uppercase(str[i]) == 1)
			str[i] += 32;
		i++;
	}
	if (ft_str_is_lowercase(str[0]) == 1)
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if (ft_str_is_lowercase(str[i]) == 1)
		{
			if (ft_str_is_alpha(str[i - 1]) == 0
				&& ft_str_is_numeric(str[i - 1]) == 0)
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
