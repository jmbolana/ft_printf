/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jmbolana <jmbolana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:31:05 by Jmbolana          #+#    #+#             */
/*   Updated: 2026/02/18 16:31:05 by Jmbolana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list ap)
{
	int	cnt;

	cnt = 0;
	if (c == 'c')
		cnt += ft_putchar(va_arg(ap, int));
	else if (c == '%')
		cnt += ft_putchar('%');
	else if (c == 's')
		cnt += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		cnt += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		cnt += ft_putunsigned(va_arg(ap, unsigned int));
	else if (c == 'p')
		cnt += ft_putptr(va_arg(ap, void *));
	else if (c == 'x' || c == 'X')
		cnt += ft_puthex(va_arg(ap, int), c);
	return (cnt);
}
