/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:32:34 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/12 19:38:57 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	t_size	len_s;

	len_s = ft_strlen((char *)s);
	if ((*s == '\0') && (c == '\0'))
		return ((char *)s);
	while (len_s + 1)
	{
		if (s[len_s] == c)
			return ((char *)s + len_s);
		len_s--;
	}
	return (T_NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	const char	str[] = "bonjour";
	int			c;

	c = 's';
	printf("%s\n", ft_strrchr(str, c));
	printf("///////\n");
	printf("%s\n", strrchr(str, c));
	return (0);
}*/
