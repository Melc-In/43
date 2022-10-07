/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:34 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/07 04:07:11 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	t_size	len_s;
	void	*null;

	len_s = ft_strlen((char *)s);
	null = (void *)0;
	while (s[len_s])
	{
		if (s[len_s] == c)
			return ((char *)s + len_s);
		len_s--;
	}
	if ((*s == '\0') && (c == '\0'))
		return ((char *)s);
	return (null);
}

