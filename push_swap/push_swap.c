/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:15 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/20 02:30:52 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	size_t	i;

	i = 0;
	a.size = 0;
	if (argc < 2)
		return (1);
	if (parsing(argc, argv, &a))
	{
		switch_algo(&a);
		free(a.nums);
		return (0);
	}
	else
	{
		ft_putstr_fd("Error\n", 1);
		free(a.nums);
		return (1);
	}
}
