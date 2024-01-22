/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:15 by cglandus          #+#    #+#             */
/*   Updated: 2024/01/18 16:52:53 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;

	a.size = 0;
	if (argc < 2)
		return (-1);
	if (parsing(argc, argv, &a))
	{
		switch_algo(&a);
		free(a.nums);
		return (0);
	}
	ft_putstr_fd("Error\n", 2);
	free(a.nums);
	return (-1);
}
