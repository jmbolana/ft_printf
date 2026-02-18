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

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_putnbr(-n) + 1);
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += write(1, &"0123456789"[n % 10], 1);
	return (count);
}
