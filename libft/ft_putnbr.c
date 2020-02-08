/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:46:20 by atote             #+#    #+#             */
/*   Updated: 2019/09/11 16:01:19 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	unb;

	unb = (n < 0) ? (unsigned int)(n * (-1)) : (unsigned int)n;
	if (n < 0)
	{
		ft_putchar('-');
		unb = (unsigned int)(n * (-1));
	}
	if (unb >= 10)
	{
		ft_putnbr(unb / 10);
	}
	ft_putchar((unb % 10) + 48);
}
