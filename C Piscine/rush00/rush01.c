/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:31:22 by alperrot          #+#    #+#             */
/*   Updated: 2023/08/20 21:04:18 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	draw(int repeat_time, char a, char b, char c)
{
	ft_putchar(a);
	if (repeat_time > 3)
	{
		while (repeat_time - 2 != 0)
		{
			ft_putchar(b);
			repeat_time--;
		}
	}
	if (c)
		ft_putchar(c);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x == 1 && y == 1)
		draw(1, '/', '\0', '\0');
	else if (x == 1)
	{
		draw(1, '/', '\0', '\0');
		while (y - 2 > 0)
		{
			draw(1, '*', '\0', '\0');
			y--;
		}
		draw(1, '\\', '\0', '\0');
	}
	else if (y == 1)
		draw(x, '/', '*', '\\');
	else
	{
		draw(x, '/', '*', '\\');
		while (y - 2 != 0)
		{
			draw(x, '*', ' ', '*');
			y--;
		}
		draw(x, '\\', '*', '/');
	}
}
