/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:07 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/11 01:24:39 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_s2;

	i = 0;
	len_s2 = ft_strlen((char *)little);
	if (!big && len == 0)
		return ((char *) big);
	if (!*little)
		return ((char *)big);
	while (*big && i <= len)
	{	
		if (ft_strncmp(big, little, len_s2) == 0)
			if (len_s2 + i <= len)
				return ((char *)big);
		big++;
		i++;
	}
	return (T_NULL);
}
