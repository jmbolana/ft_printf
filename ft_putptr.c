/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jmbolana <jmbolana@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:05:13 by Jmbolana          #+#    #+#             */
/*   Updated: 2026/02/18 17:05:13 by Jmbolana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbrbase(unsigned long long addr)
{
	int			count;
	char		*s;

	s = "0123456789abcdef";
	count = 0;
	if (addr >= 16)
		count += ft_putnbrbase(addr / 16);
	count += ft_putchar(s[addr % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	int					cnt;

	if (!ptr)
		return (ft_putstr("(nil)"));
	cnt = 0;
	addr = (unsigned long long)ptr;
	cnt += ft_putstr("0x");
	cnt += ft_putnbrbase(addr);
	return (cnt);
}
