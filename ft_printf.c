/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmbolana <jmbolana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:43:01 by jmbolana          #+#    #+#             */
/*   Updated: 2026/03/01 19:43:01 by jmbolana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			count += ft_putchar(format[i]);
		else
		{
			if (ft_isvalid(format[i + 1]))
				count += ft_format(format[++i], ap);
			else
				count += ft_putchar(format[++i]);
		}
		i++;
	}
	va_end(ap);
	return (count);
}
