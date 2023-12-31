/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:38:20 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/31 10:13:50 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int		*nums;
	size_t	size;
	size_t	filled;
}			t_stack;

int		parsing(int ac, char **args, t_stack *stack);
void	switch_algo(t_stack *a);

int		is_number(char *str);
int		in_stack(t_stack *stack, long n);
size_t	size_stack(char **tab);
int		is_sorted(t_stack *stack);

void	swap(t_stack *stack, char *mess);
void	push(t_stack *s1, t_stack *s2, char *mess);
void	rotate(t_stack *stack, char *mess);

void	ss(t_stack *a, t_stack *b, char *mess);
void	rr(t_stack *a, t_stack *b, char *mess);
void	rrab(t_stack *stack, char *mess);
void	rrr(t_stack *a, t_stack *b, char *mess);

#endif
