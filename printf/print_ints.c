/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:29:56 by cglandus          #+#    #+#             */
/*   Updated: 2022/12/15 15:53:35 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ints(int n)
{
	int	nb;
	int	len;

	nb = absol(n);
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
