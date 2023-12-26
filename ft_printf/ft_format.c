/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:29:32 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/22 19:13:30 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list arg)
{
	int		count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr((long)va_arg(arg, int));
	else if (c == '%')
		count += ft_putchar('%');
	else
		count += ft_putchar(c);
	return (count);
}
