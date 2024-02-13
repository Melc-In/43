/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:32:28 by cglandus          #+#    #+#             */
/*   Updated: 2024/02/06 15:24:05 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dest;

	i = 0;
	if (!dst && size == 0)
		return (0);
	len_dest = ft_strlen(dst);
	if (size > len_dest)
	{
		while ((i < size - len_dest - 1) && src[i])
		{
			dst[len_dest + i] = src[i];
			i++;
		}
		dst[len_dest + i] = '\0';
		return (ft_strlen(src) + len_dest);
	}
	return (ft_strlen(src) + size);
}
