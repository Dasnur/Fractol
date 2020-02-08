#include "libft.h"

int		ft_getnbr(char *str)
{
	int		i;
	int		nbr;
	int		flag;

	flag = 0;
	i = 0;
	nbr = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			flag = 1;
			i++;
		}
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	if (flag == 1)
		nbr = nbr * -1;
	return (nbr);
}