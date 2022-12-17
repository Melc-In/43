/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:30:06 by cglandus          #+#    #+#             */
/*   Updated: 2022/12/16 19:03:20 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
