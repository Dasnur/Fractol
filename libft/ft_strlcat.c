/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:13:23 by atote             #+#    #+#             */
/*   Updated: 2019/09/13 19:36:13 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	p;
	size_t	l;
	size_t	t;

	p = 0;
	i = 0;
	l = 0;
	while (dst[i] != '\0')
		i++;
	while (src[l] != '\0')
		l++;
	t = i + l;
	if (size <= i)
		return (size + l);
	while ((i < (size - 1)) && (src[p] != '\0'))
	{
		dst[i] = src[p];
		i++;
		p++;
	}
	dst[i] = '\0';
	return (t);
}
