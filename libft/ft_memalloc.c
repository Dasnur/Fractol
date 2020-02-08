/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:23:36 by atote             #+#    #+#             */
/*   Updated: 2019/09/11 17:41:22 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*res;
	long long int	ch;

	ch = (long long int)(size);
	if (ch < 0)
		return (NULL);
	res = (void *)malloc(size);
	if (!res)
		return (NULL);
	ft_bzero(res, size);
	return (res);
}
