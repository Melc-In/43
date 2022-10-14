/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:22:59 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/12 18:53:23 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (T_NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	const char	str[] = "bonjour";
	int			c;

	c = 'b';
	printf("%s\n", ft_strchr(str, c));
	printf("////////\n");
	printf("%s\n", strchr(str, c));
	return (0);
}*/
