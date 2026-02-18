/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jmbolana <jmbolana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:15:42 by Jmbolana          #+#    #+#             */
/*   Updated: 2026/02/18 13:05:01 by jmbolana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	c;
	int		count;

	if (n == 0)
		return (ft_putchar('0'));
	if (n == INT_MIN)
		return (ft_putstr("-2147483648"));
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n / 10 > 0)
		count += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	count += ft_putchar(c);
	return (count);
}
