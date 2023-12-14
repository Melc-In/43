/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:03:17 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/14 14:12:51 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb > UINT_MAX && size != 0)
		return (NULL);
	if (nmemb == 0 && size > UINT_MAX)
	{
		ptr = malloc(size * nmemb);
		if (!ptr)
			return (NULL);
		ft_bzero(ptr, nmemb * size);
		return (ptr);
	}
	if (nmemb * size > SIZE_MAX
		|| nmemb >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	if (nmemb < 0 || size > UINT_MAX
		|| size * nmemb < 0)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
