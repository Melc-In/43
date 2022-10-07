/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 01:03:17 by cglandus          #+#    #+#             */
/*   Updated: 2022/10/07 01:45:19 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(t_size nmemb, t_size size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0 || nmemb * size > 2147483647)
		return (malloc(0));
	ptr = malloc(size * nmemb);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
