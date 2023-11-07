/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_correct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberduck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:53:59 by nberduck          #+#    #+#             */
/*   Updated: 2023/08/26 20:24:44 by nberduck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_viewX(int view, char *str, int n)
{
	if(ViewStagesX() == 1)
		return 1;
	return n;
}
int	ft_viewY(int view, char *str, int n)
{
	if(ViewStagesY() == 1)
		return 1;
	return n;
}

int ft_view(int views, char *str)
{
	int	n;
	int x;
	int y;

	n = 0;
	while(str[n])
	{
		x = ft_viewX(views,str,n);
		y = ft_viewY(views,str,n);
		if(!(x == 1 && y == 1))
			return n;
		n++;
	}
	return 1;
}
