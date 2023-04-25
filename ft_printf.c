/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakshmi <alakshmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:47:12 by alakshmi          #+#    #+#             */
/*   Updated: 2022/12/02 20:53:07 by alakshmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>

int	ft_putxs(unsigned int num, const char *base)
{
	if (num > 15)
		return (ft_putxs(num / 16, base) + ft_putchar(base[num % 16]));
	return (ft_putchar(base[num % 16]));
}

int	func_to_perform(va_list ptr, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	else if (c == 'p')
		return (ft_putstr("0x") + ft_putp(va_arg(ptr, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ptr, int)));
	else if (c == 'u')
		return (ft_putuint(va_arg(ptr, unsigned int)));
	else if (c == 'x')
		return (ft_putxs(va_arg(ptr, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putxs(va_arg(ptr, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	char	c;
	va_list	ptr;
	int		len;

	i = 0;
	len = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			c = str[++i];
			len += func_to_perform(ptr, c);
		}
		else
			len += write (1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}
