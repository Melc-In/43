/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:29:56 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/23 14:20:05 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_ints(int n)
{
	int	nb;
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
	return (len);
}
