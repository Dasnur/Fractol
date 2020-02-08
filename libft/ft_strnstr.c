/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:47:03 by atote             #+#    #+#             */
/*   Updated: 2019/09/16 21:36:35 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		k;
	char		*t;
	char		*p;
	size_t		i;

	k = 0;
	i = 0;
	t = (char*)(&(big[k]));
	p = t;
	if (ft_strlen(little) == 0)
		return (t);
	while ((t[i] != '\0') && (little[i] != '\0'))
	{
		if (t[i] == little[i])
			i++;
		else
		{
			t = p++;
			i = 0;
			k++;
		}
	}
	if ((little[i] == '\0') && ((k + i) <= len + 1))
		return (t);
	return (NULL);
}
