/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 03:24:44 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/12 17:52:13 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, t_size n)
{
	unsigned char	*cpy_s1;
	unsigned char	*cpy_s2;

	cpy_s1 = (unsigned char *)s1;
	cpy_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (!(*cpy_s1 == *cpy_s2))
			return (*cpy_s1 - *cpy_s2);
		cpy_s1++;
		cpy_s2++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	t_size	n;
	//char	test[] = "t\200";
	//char	test2[] = "t\0";
	char	s[] = {-128, 0, 127, 0};
	char	s2[] = {0, 0, 127, 0};

	n = 1;
	printf("%d\n", ft_memcmp(s, s2, n));
	printf("////////\n");
	printf("%d\n", memcmp(s, s2, n));
	return (0);
}*/
