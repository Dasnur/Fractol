/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:08:07 by atote             #+#    #+#             */
/*   Updated: 2019/09/08 18:53:42 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	long long int	ch;

	ch = (long long int)(n);
	if (ch < 0)
		return (NULL);
	i = 0;
	dest1 = (unsigned char*)dest;
	while (i < n)
	{
		dest1[i] = c;
		i++;
	}
	return (dest1);
}
