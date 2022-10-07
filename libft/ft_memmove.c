/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:13:23 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/03 19:49:24 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, t_size n)
{
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest2 > src2)
		while (dest2++ && src2++ && n--)
			*dest2 = *src2;
	else
	{
		while (dest2[n] && src2[n] && n)
		{
			dest2[n] = src2[n];
			n--;
		}
	}
	return (dest);
}
