/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:28:16 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/22 19:13:40 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int		count;
	int		i;

	count = 0;
	if (!str)
	{
		count += ft_printf("(null)");
		return (count);
	}
	i = 0;
	while (str[i])
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
