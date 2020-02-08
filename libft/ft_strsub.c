/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:10:29 by atote             #+#    #+#             */
/*   Updated: 2019/09/11 16:29:07 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	int				i;
	long long int	ch;

	ch = (long long int)(len);
	if (ch < 0)
		return (NULL);
	i = 0;
	res = malloc(sizeof(char) * (len + 1));
	if ((!res) || (!s))
		return (NULL);
	while (len > 0)
	{
		res[i] = s[start];
		i++;
		start++;
		len--;
	}
	res[i] = '\0';
	return (res);
}
