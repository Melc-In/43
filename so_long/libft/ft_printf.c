/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:39:42 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/20 18:39:23 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_ints(int n)
{
	int	nb;
	int	len;

	nb = ft_abs(n);
	len = 1;
	ft_putnbr_fd(n, 1);
	if (n < 0)
		len++;
	while (nb > 9)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int	print_uints(unsigned int n)
{
	size_t	size;

	size = 0;
	if (n <= 9)
		return (ft_putchar_fd(n + '0', 1));
	if (n > 9)
	{
		size += ft_putnbr_fd(n / 10, 1);
		size += ft_putchar_fd(n % 10 + '0', 1);
	}
	return (size);
}

int	print_ptr_hex(unsigned long long ptr, unsigned int n, char c, int wtp)
{
	int	len;

	if (wtp == 1)
	{
		if (!ptr)
			return (ft_putstr_fd("(nil)", 1));
		len = write(1, "0x", 2);
		len += ft_putnbr_base_fd(ptr, "0123456789abcdef", 1);
		return (len);
	}
	else
	{
		if (c == 'X')
			return (ft_putnbr_base_fd(n, "0123456789ABCDEF", 1));
		if (c == 'x')
			return (ft_putnbr_base_fd(n, "0123456789abcdef", 1));
		return (0);
	}
}

static int	parsing_printf(const char *str, va_list ap)
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
		return (print_ptr_hex(0, va_arg(ap, unsigned int), *str, 0));
	if (*str == 'p')
		return (print_ptr_hex(va_arg(ap, unsigned long long), 0, *str, 1));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			len;
	int			err[2];

	if (!str)
		return (-1);
	va_start(ap, str);
	len = 0;
	ft_bzero(err, 2 * sizeof(int));
	while (*str)
	{
		if (*str == '%')
		{
			err[0] = parsing_printf(++str, ap);
			err[1] = err[0] == -1;
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
