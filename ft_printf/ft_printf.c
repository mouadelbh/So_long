/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:47:11 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/12/22 19:13:35 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	if (!format)
		return (-1);
	va_start(arg, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break ;
			count += ft_format(*format, arg);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (count);
}
