/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 03:24:44 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/05 03:33:40 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, t_size)
{
	unsigned char cpy_s1;
	unsigned char cpy_s2;
	int	i;

	i = 0;
	cpy_s1 = (unsigned char *)s1;
	cpy_s2 = (unsigned char *)s2;
	while ((cpy_s1[i] != '\0' && cpy_s2 != '\0') || i < n)
	{
		if (!(cpy_s1 == cpy_s2))
			return (cpy_s1 - cpy_s2);
		i++;
	}
	return (cpy_s1 - cpy_s2);
}
