/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakshmi <alakshmi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:56:27 by alakshmi          #+#    #+#             */
/*   Updated: 2022/11/27 17:02:34 by alakshmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putuint(unsigned int n)
{
	if (n > 9)
		return (ft_putuint(n / 10) + ft_putchar("0123456789"[n % 10]));
	return (ft_putchar("0123456789"[n % 10]));
}

int	ft_putnbr(long nb)
{
	if (nb < 0)
		return (ft_putchar('-') + ft_putnbr(-nb));
	if (nb > 9)
		return (ft_putnbr(nb / 10) + ft_putchar("0123456789"[nb % 10]));
	return (ft_putchar("0123456789"[nb % 10]));
}

int	ft_putstr(char *s)
{
	size_t	i;
	int		len;

	len = 0;
	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	while (s[i])
		len += ft_putchar(s[i++]);
	return (len);
}

int	ft_putp(void *ptr)
{
	unsigned long	num;

	num = (unsigned long)ptr;
	if (num > 15)
		return (ft_putp((void *)(num / 16)) +
			ft_putchar("0123456789abcdef"[num % 16]));
	return (ft_putchar("0123456789abcdef"[num % 16]));
}
