/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 06:55:06 by cglandus          #+#    #+#             */
/*   Updated: 2024/01/12 04:34:30 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	doperator_switch(t_stack *s1, t_stack *s2, char *arg)
{
	if (ft_strncmp(arg, "rr\n", 5) == 0)
		rr(s1, s2, "");
	else if (ft_strncmp(arg, "rra\n", 5) == 0)
		rrab(s1, "");
	else if (ft_strncmp(arg, "rrb\n", 5) == 0)
		rrab(s2, "");
	else if (ft_strncmp(arg, "rrr\n", 5) == 0)
		rrr(s1, s2, "");
	else
		return (0);
	return (1);
}

static int	operator_switch(t_stack *s1, t_stack *s2, char *arg)
{
	if (ft_strncmp(arg, "sa\n", 5) == 0)
		swap(s1, "");
	else if (ft_strncmp(arg, "sb\n", 5) == 0)
		swap(s2, "");
	else if (ft_strncmp(arg, "ss\n", 5) == 0)
		ss(s1, s2, "");
	else if (ft_strncmp(arg, "pa\n", 5) == 0)
		push(s1, s2, "");
	else if (ft_strncmp(arg, "pb\n", 5) == 0)
		push(s2, s1, "");
	else if (ft_strncmp(arg, "ra\n", 5) == 0)
		rotate(s1, "");
	else if (ft_strncmp(arg, "rb\n", 5) == 0)
		rotate(s2, "");
	else
		return (doperator_switch(s1, s2, arg));
	return (1);
}

static void	checker(t_stack *s1, t_stack *s2, char *arg)
{
	while (1)
	{
		arg = get_next_line(0);
		if (!arg)
			break ;
		
		if (!operator_switch(s1, s2, arg))
		{
			free(arg);
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		free(arg);
	}
	if (is_sorted(s1))
	{
		ft_putstr_fd("OK\n", 1);
	}
	else
		ft_putstr_fd("KO\n", 2);
}

int	main(int argc, char **argv)
{
	t_stack	s1;
	t_stack	s2;
	char	*arg = NULL;

	s1.size = 0;
	if (argc < 2)
		return (-1);
	if (parsing(argc, argv, &s1))
	{
		s2.nums = ft_calloc(s1.size, sizeof(int));
		s2.size = s1.size;
		if (s2.nums)
		{
			checker(&s1, &s2, arg);
			free(s2.nums);
		}
		free(s1.nums);
		return (0);
	}
	ft_putstr_fd("Error\n", 2);
	free(s1.nums);
	return (-1);
}
/*
#include <stdio.h>

int	main()
{
	t_stack	a;

	a.size = 3;
	a.nums = ft_calloc(3 , sizeof(int));
	a.nums[0] = 0;
	a.nums[1] = 1;
	a.nums[2] = -1;
	rrab(&a, "rra\n");
	if (is_sorted(&a))
		printf("SORTED");
 	free(a.nums);
	return (0);
}*/