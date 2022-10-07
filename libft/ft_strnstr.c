/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:07 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/07 03:49:18 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, t_size n)
{
	void	*null;
	t_size	i;
	t_size	len_s2;

	i = 0;
	len_s2 = ft_strlen((char *)s2);
	null = (void *)0;
	while (s1 && i < n)
	{	
		if (ft_memcmp(s1, s2, len_s2) == 0)
			return ((char *)s1);
		else
			s1++;
		i++;
	}
	if (*s2 == '\0')
		return ((char *)s1);
	return (null);
}
