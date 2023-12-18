/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:15 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/18 22:55:25 by cglandus         ###   ########.fr       */
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
		while (i < a.size)
		{
			ft_putnbr_fd(a.nums[i], 1);
			ft_putchar_fd('\n', 1);
			i++;
		}
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
