/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:29:58 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/23 20:50:34 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long long ptr)
{
	int	len;

	len = write(1, "0x", 2);
	len += ft_putnbr_base_fd(ptr, "0123456789abcdef", 1);
	return (len);
}	
