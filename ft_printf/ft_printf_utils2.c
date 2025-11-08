/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardet- <lbardet-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 07:03:55 by lbardet-          #+#    #+#             */
/*   Updated: 2025/10/24 03:10:04 by lbardet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_base(unsigned long n, const char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex_base(n / 16, base);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_puthex(unsigned int n, int upper)
{
	const char	*base;

	if (upper == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (ft_puthex_base((unsigned long)n, base));
}

int	ft_putptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex_base((unsigned long)ptr, "0123456789abcdef");
	return (count);
}
