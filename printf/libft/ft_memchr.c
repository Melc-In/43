/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:14:25 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/11 01:23:33 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*s2;
	size_t				i;

	s2 = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (T_NULL);
	while (i < n)
	{
		if ((unsigned char)s2[i] == (unsigned char)c)
			return (s2 + i);
		i++;
	}
	return (T_NULL);
}
