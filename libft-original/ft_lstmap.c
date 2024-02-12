/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alperrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:47:31 by alperrot          #+#    #+#             */
/*   Updated: 2024/02/12 14:26:08 by alperrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	while (lst)
	{
		tmp = lst->next;
		f(lst->content);
		new->content = lst->content;
		new->next = tmp;
		new = new->next;
		lst = tmp;
	}
	return (new);
}
