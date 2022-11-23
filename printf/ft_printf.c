/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:39:42 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/23 20:53:23 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parsing(const char str, va_list args)
{
	if (*str == 'c')
		return (ft_putchar_fd(va_args(args, char), 1));
	if (*str == 's')
		return (ft_putstr_fd(va_args(args, char *), 1));
	if (*str == '%')
		return (write(1, "%", 1));
	if (*str == 'd' || *str == 'i')
		return (print_ints(va_args(args, int)));
	if (*str == 'u')
		return (print_uints(va_args(args, unsigned int));
	if (*str == 'x' || *str == 'X')
		return (print_hex(va_args(args, int), *str));
	if (*str == 'p')
		return (print_ptr(va_args(args, void *)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			len;

	if (!str)
		return (-1);
	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			len += parsing(++str, args);
			if (parsing(str, args) == 0)
				return (-1);
			str++;
		}
		else
			len += write(1, str++, 1);
	}
	va_end(va);
	return (len);
}

int	main()
{
	int	a;
	a = ft_printf("%%heh");
	ft_printf("\n%d\n", a);
}
