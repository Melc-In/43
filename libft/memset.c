/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:16:37 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/03 17:26:52 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, t_size n)
{
	unsigned char	*temp;

	temp = (unsigned char *)s;
	while (n--)
		*temp++ = c;
	return (s);
}
