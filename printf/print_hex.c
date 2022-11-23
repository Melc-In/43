/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:29:55 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/23 20:51:05 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(int n)
{
	int	len;

	len = 0;
	if (*str == 'X')
		return (ft_putnbr_base_fd(n, "0123456789ABCDEF", 1));
	if (*str == 'x')
		return (ft_putnbr_base_fd(n, "0123456789abcdef", 1));
}
