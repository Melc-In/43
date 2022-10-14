/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:13:23 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/11 15:15:28 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, t_size n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	t_size			i;

	i = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (dest < src)
	{
		while (n > i)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	if (dest > src)
		while (n--)
			dest2[n] = src2[n];
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int	main()
{
	char	src[] = "loremi";
	char	dest[] = "heewa";
	char	dest2[] = "abcde";
	
	printf("1 - %s\n", (char *)ft_memmove(dest, src, 5));
	printf("///////////////////\n");
	printf("2 - %s\n", (char *)memmove(dest2, src, 5));
}*/
