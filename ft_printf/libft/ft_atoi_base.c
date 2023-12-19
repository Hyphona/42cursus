/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:13:52 by alperrot          #+#    #+#             */
/*   Updated: 2023/12/19 12:56:12 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *str, char *base)
{
	int		n;
	int		neg;

	if (!base || !ft_check_base(base))
		return (0);
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
	while (ft_strchr(base, *str) && *ft_strchr(base, *str) != '\0')
	{
		n = (n * ft_strlen(base)) + (ft_strchr(base, *str) - base);
		str++;
	}
	return (n * neg);
}
