/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <alperrot@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:40:11 by alperrot          #+#    #+#             */
/*   Updated: 2023/11/06 18:47:23 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (str[i] != '\0')
	{
		while (str[i])
		{
			if (str[i] == c)
				return (&str[i]);
			i++;
		}
	}
	return ((void *) 0);
}
