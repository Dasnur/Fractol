/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:14:51 by atote             #+#    #+#             */
/*   Updated: 2019/09/13 19:21:11 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pts;
	size_t			i;
	long long int	ch;

	ch = (long long int)(n);
	i = 0;
	pts = (unsigned char *)(s);
	if (ch < 0)
		return (NULL);
	while (i < n)
	{
		if (*pts == (unsigned char)(c))
			return ((void*)(pts));
		i++;
		pts++;
	}
	return (NULL);
}
