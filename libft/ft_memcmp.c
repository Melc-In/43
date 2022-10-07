/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 03:24:44 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/07 02:31:55 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, t_size n)
{
	unsigned char	*cpy_s1;
	unsigned char	*cpy_s2;
	t_size			i;

	i = 0;
	cpy_s1 = (unsigned char *)s1;
	cpy_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (!(cpy_s1[i] == cpy_s2[i]))
			return (cpy_s1[i] - cpy_s2[i]);
		i++;
	}
	return (cpy_s1 - cpy_s2);
}
