/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:03:04 by atote             #+#    #+#             */
/*   Updated: 2019/09/16 20:16:43 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if ((!lst) || (!f))
		return (NULL);
	new = (*f)(lst);
	tmp = new;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp->next = (*f)(lst);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (new);
}
