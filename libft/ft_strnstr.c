/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:07 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/12 18:29:09 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, t_size n)
{
	t_size	i;
	t_size	len_s2;

	i = 0;
	len_s2 = ft_strlen((char *)s2);
	while (s1 && i + len_s2 < n)
	{	
		if (ft_memcmp(s1, s2, len_s2) == 0)
			return ((char *)s1);
		s1++;
		i++;
	}
	if (*s2 == '\0')
		return ((char *)s1);
	return (T_NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	const char	s1[] = "lorem ipsum dolor sit amet";
	const char	s2[] = "dolor";
	t_size	n;

	n = 13;
	printf("%s\n", ft_strnstr(s1, s2, n));
}*/
