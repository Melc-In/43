/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:07 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/14 02:17:37 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_s2;

	i = 0;
	if ((!big && len == 0) || !*little)
		return ((char *)big);
	len_s2 = ft_strlen((char *)little);
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
