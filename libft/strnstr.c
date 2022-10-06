/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:07 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/05 03:39:16 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, t_size n)
{
	t_size	len_s2;

	len_s2 = ft_strlen(s2);
	while (s1)
	{	
		if (ft_memcmp(s1, s2, len_s2) = 0)
			return (s1);
		else
			s1++;
	}
	if (s2 == '\0')
		return (s1);
	return (t_NULL);
}
