/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:30:06 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/23 14:26:12 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uints(unsigned int n)
{
	unsigned int	nb;
	int	len;

	nb = n;
	len = 1;
	ft_putnbr_fd(nb, 1);
	if (nb < 0)
		len++;
	while (nb > 9)
	{
		len++;
		nb /= 10;
	}
	return(len);
}
