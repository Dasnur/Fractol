/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:11:07 by atote             #+#    #+#             */
/*   Updated: 2019/09/16 19:50:44 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	p;
	int	t;

	t = 0;
	p = 0;
	i = 0;
	while (haystack[p] != '\0')
	{
		if (needle[i] == haystack[p++])
			i++;
		else
		{
			p = ++t;
			i = 0;
		}
		if ((needle[i] == '\0') && (i == 0))
			return ((char *)(&(haystack[0])));
		if (needle[i] == '\0')
			return ((char *)(&(haystack[t])));
	}
	if ((haystack[p] == '\0') && ((needle[i]) == '\0'))
		return ((char*)(&(haystack[0])));
	return (NULL);
}
