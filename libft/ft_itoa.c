/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:00:03 by atote             #+#    #+#             */
/*   Updated: 2019/09/16 16:48:42 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_len(int n)
{
	unsigned int	len;
	unsigned int	nb;

	if (n < 0)
		nb = (unsigned int)(n * (-1));
	else
		nb = (unsigned int)n;
	len = 1;
	while (nb > 10)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char			*revs(char *s, int i, int n)
{
	char	*res;
	int		len;
	int		k;

	k = 0;
	if (n < 0)
		len = get_len(n) + 1;
	else
		len = get_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[k] = '-';
		k++;
	}
	while (i > 0)
	{
		res[k] = s[i - 1];
		k++;
		i--;
	}
	res[k] = '\0';
	return (res);
}

char				*ft_itoa(int n)
{
	char				*buf;
	int					i;
	char				*res;
	unsigned long int	nb;

	i = 0;
	nb = (n < 0) ? (unsigned int)(n * (-1)) : (unsigned int)n;
	buf = (char*)malloc(sizeof(char) * (get_len(n) + 1));
	if (!buf)
		return (NULL);
	if (nb == 0)
	{
		buf[0] = '0';
		return (buf);
	}
	while (nb > 0)
	{
		buf[i] = (char)(nb % 10 + 48);
		nb = nb / 10;
		i++;
	}
	res = revs(buf, i, n);
	return (res);
}
