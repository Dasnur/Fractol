/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:13:58 by atote             #+#    #+#             */
/*   Updated: 2019/09/11 16:21:25 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unb;

	unb = (n < 0) ? (unsigned int)(n * (-1)) : (unsigned int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		unb = (unsigned int)(n * (-1));
	}
	if (unb >= 10)
		ft_putnbr_fd(unb / 10, fd);
	ft_putchar_fd((unb % 10) + 48, fd);
}
