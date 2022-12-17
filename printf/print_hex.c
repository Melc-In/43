/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:29:55 by cglandus          #+#    #+#             */
/*   Updated: 2022/12/16 22:27:01 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int n, char c)
{
	if (c == 'X')
		return (ft_putnbr_base_fd(n, "0123456789ABCDEF", 1));
	if (c == 'x')
		return (ft_putnbr_base_fd(n, "0123456789abcdef", 1));
	return (0);
}
