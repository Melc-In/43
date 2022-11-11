/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:03:17 by cglandus          #+#    #+#             */
/*   Updated: 2022/11/08 03:34:36 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb * size > SIZE_MAX
		|| nmemb >= SIZE_MAX || size >= SIZE_MAX)
		return (T_NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (T_NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
