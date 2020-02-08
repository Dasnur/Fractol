/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:02:25 by atote             #+#    #+#             */
/*   Updated: 2019/09/16 16:43:48 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	mkfree(int index, char **map)
{
	while (index > 0)
	{
		free(map[index]);
		index--;
	}
}

static int	get_count_str(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (flag == 0))
		{
			count++;
			flag = 1;
		}
		if (s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

static char	*get_str(char const *s, int i, char c)
{
	char	*res;
	int		k;
	int		start;

	start = i;
	k = 0;
	while ((s[i] != '\0') && (s[i] != c))
	{
		k++;
		i++;
	}
	res = (char *)malloc(sizeof(char) * (k + 1));
	if (!res)
		return (NULL);
	k = 0;
	while ((s[start] != '\0') && (s[start] != c))
	{
		res[k] = s[start++];
		k++;
	}
	res[k] = '\0';
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**res;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (get_count_str(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			res[k] = get_str(s, i, c);
			res[k] == NULL ? mkfree(k - 1, res) : k++;
			while ((s[i] != '\0') && (s[i] != c))
				i++;
		}
	}
	res[k] = NULL;
	return (res);
}
