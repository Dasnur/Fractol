/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 20:46:02 by atote             #+#    #+#             */
/*   Updated: 2019/09/16 16:50:18 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*newcontent(void const *content, size_t content_size)
{
	unsigned char	*pt;
	unsigned char	*ptn;
	void			*new;
	size_t			i;

	i = 0;
	new = (void*)malloc(sizeof(size_t) * content_size);
	if (!new)
		return (NULL);
	if (content == NULL)
		return (NULL);
	pt = (unsigned char *)content;
	ptn = (unsigned char *)new;
	while (i < content_size)
	{
		*ptn = *pt;
		ptn++;
		pt++;
		i++;
	}
	return (new);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*new;
	long long int	ch;

	ch = content_size;
	if (ch < 0)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = newcontent(content, content_size);
	new->content_size = content_size;
	if (content == NULL)
		new->content_size = 0;
	new->next = NULL;
	return (new);
}
