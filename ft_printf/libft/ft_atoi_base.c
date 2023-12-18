/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:13:52 by alperrot          #+#    #+#             */
/*   Updated: 2023/12/18 12:30:54 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *str, char *base)
{
	size_t	i;
	int		n;
	int		neg;
	int		base_len;

	i = 0;
	n = 0;
	neg = 1;
	base_len = ft_strlen(base);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (*ft_strchr(base, str[i]) != '\0')
	{
		n = (n * base_len) + (ft_strchr(base, str[i]) - base);
		i++;
	}
	n = n * neg;
	return (n);
}
