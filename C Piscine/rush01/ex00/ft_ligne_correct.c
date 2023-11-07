/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ligne_correct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberduck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:31:01 by nberduck          #+#    #+#             */
/*   Updated: 2023/08/26 20:21:30 by nberduck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_lignX_correct(char *str, int place, int ps)
{
	if(ps == 0)
	{
		if(ps + (ps + 4) + (ps + 8) + (ps + 12) == 10)
			return 1;
		return place;
	}
	if(ps == 1)
	{
		if(ps + (ps - 4) + (ps + 8) + (ps + 12) == 10)
			return 1;
		return place;
	}
	if(ps == 2)
	{
		if(ps + (ps + 4) + (ps - 8) + (ps + 12) == 10)
			return 1;
		return place;
	}
	if(ps == 3)
	{
		if(ps + (ps + 4) + (ps + 8) + (ps - 12) == 10)
			return 1;
		return place;
	}

}

int	ft_lignY_correct(char *str, int place, int ps)
{
	if(ps == 0)
	{
		if (ps + (ps + 1) + (ps + 2) + (ps + 3) == 10)
			return 1;
		return place;
	}
	if(ps == 1)
	{
		if(ps + (ps-1) + (ps+2) + (ps + 3) == 10)
			return 1;
		return place;
	}
	if(ps == 1)
	{
		if(ps + (ps+1) + (ps-2) + (ps + 3) == 10)
			return 1;
		return place;
	}
	if(ps == 1)
	{
		if(ps + (ps+1) + (ps+2) + (ps - 3) == 10)
			return 1;
		return place;
	}
}

int ft_ligne(char *str, int	place)
{
	int	ps;

	ps = ft_place(place);
	if(ft_lignY_correct(str,place,ps) == 1 && ft_lignX_correct(str,place,ps) == 1)
		return 1;
	else 
		return place;

}

int ft_place(int place)
{
	if(place == 1)
		return 1;
	if(place == 2)
		return 2;
	if(place == 3)
		return 3;
	if(place == 4)
		return 4;
	return 0;
}
