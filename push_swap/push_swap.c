/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:15 by cglandus          #+#    #+#             */
/*   Updated: 2023/07/31 09:04:51 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if (parsing(argv))
	{
		//sort 
		return (0);
	}
	else
	{
		ft_putstr_fd("Error \n", 1);
		return (1);
	}
}
