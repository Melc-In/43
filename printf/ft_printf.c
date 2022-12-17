/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:39:42 by cglandus          #+#    #+#             */
/*   Updated: 2022/12/16 22:51:30 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parsing(const char *str, va_list ap)
{
	if (*str == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 1));
	if (*str == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1));
	if (*str == '%')
		return (write(1, "%", 1));
	if (*str == 'd' || *str == 'i')
		return (print_ints(va_arg(ap, int)));
	if (*str == 'u')
		return (print_uints(va_arg(ap, unsigned int)));
	if (*str == 'x' || *str == 'X')
		return (print_hex(va_arg(ap, unsigned int), *str));
	if (*str == 'p')
		return (print_ptr(va_arg(ap, unsigned long long)));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			len;
	int			err[2];

	err[0] = 0;
	err[1] = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			err[0] = parsing(++str, ap);
			if (err[0] == -1)
				err[1] = 1;
			len += err[0];
			str++;
		}
		else
			len += write(1, str++, 1);
	}
	if (err[1])
		len = -1; 
	va_end(ap);
	return (len);
}
