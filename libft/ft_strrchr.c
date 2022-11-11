/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:34 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/11 01:22:45 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len_s;

	len_s = ft_strlen((char *)s);
	if ((*s == '\0') && (c == '\0'))
		return ((char *)s);
	while (len_s + 1)
	{
		if (s[len_s] == (char)c)
			return ((char *)s + len_s);
		len_s--;
	}
	return (T_NULL);
}
