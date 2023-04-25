/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alakshmi <alakshmi@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:54:12 by alakshmi          #+#    #+#             */
/*   Updated: 2022/11/27 16:55:52 by alakshmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *ptr, ...);
int	ft_putchar(char c);
int	ft_putuint(unsigned int n);
int	ft_putnbr(long nb);
int	ft_putstr(char *s);
int	ft_putp(void *ptr);
int	ft_putxs(unsigned int num, const char *base);

#endif