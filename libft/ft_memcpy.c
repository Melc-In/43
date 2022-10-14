/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:34:47 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/12 19:33:35 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, t_size n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	t_size			i;

	i = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	while (i < n && dest2[i] != '\0')
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
