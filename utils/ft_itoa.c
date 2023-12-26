/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:44:38 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/26 09:49:30 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_lennb(long nl)
{
	int	i;

	i = 1;
	if (nl < 0)
	{
		i++;
		nl = -nl;
	}
	while (nl > 9)
	{
		nl /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	nl;
	int		i;
	char	*nbr;
	int		len;

	i = 0;
	nl = (long)n;
	len = ft_lennb(nl);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (nbr == NULL)
		return (NULL);
	if (nl < 0)
	{
		nbr[i++] = '-';
		nl = -nl;
	}
	nbr[len] = '\0';
	len--;
	while (len >= i)
	{
		nbr[len--] = nl % 10 + '0';
		nl /= 10;
	}
	return (nbr);
}
