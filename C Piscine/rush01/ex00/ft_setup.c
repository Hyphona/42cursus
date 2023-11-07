/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:41:08 by rgobet            #+#    #+#             */
/*   Updated: 2023/08/27 16:13:45 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_line_verif(char *tab, int view);

void	ft_rev_char_tab(char *tab, int size)
{
	char	a;
	char	b;
	int		i;

	i = 0;
	while (i <= size / 2)
	{
		a = tab[i];
		b = tab[size - i - 1];
		tab[i] = b;
		tab[size - i - 1] = a;
		i++;
	}
}

int	ft_setup_line(char **tab, char *views)
{
	int		i;
	int		j;
	int		count;
	char	v[4];

	i = 0;
	j = 0;
	count = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			v[j] = tab[i][j];
			j++;
		}
		count += ft_line_verif(v, (views[i] - '0'));
		count += ft_line_verif(ft_rev_char_tab(v, 4), (views[i + 4] - '0'));
		i++;
	}
	if (count != 0)
		return (1);
	else
		return (0);
}

int	ft_setup_col(char *tab, int view)
{
	int		i;
	int		j;
	int		count;
	char	v[4];

	i = 0;
	j = 0;
	count = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			v[j + 8] = tab[j][i];
			j++;
		}
		count += ft_line_verif(v, (views[i] - '0'));
		count += ft_line_verif(ft_rev_char_tab(v, 4), (views[i + 12] - '0'));
		i++;
	}
	if (count != 0)
		return (1);
	else
		return (0);
}

int	ft_line_verif(char *tab, int view)
{
	int		pos;
	int		count;
	char	max;

	pos = 0;
	count = 1;
	max = tab[0];
	while (pos < 4)
	{
		if (tab[pos] > max)
		{
			max = tab[pos];
			count++;
		}
		pos++;
	}
	if (count == view)
		return (0);
	else
		return (1);
}
