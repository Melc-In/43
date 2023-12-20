/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortalgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:58:04 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/20 02:32:38 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  under6_handler(t_stack *a, t_stack *b)
{
    b->filled++;
    if (a->size == 2)
    {
        if (!(is_sorted(a)))
            swap(a, "sa\n");
        return (1);
    }
    if (a->size == 3)
    {
        return (0);
    }
    return (0);
}

int    switch_algo(t_stack *a)
{
    t_stack b;

    b.nums = ft_calloc(a->size, sizeof(int));
    b.size = a->size;
    b.filled = 0;

    if (is_sorted(a))
    {
        free(b.nums);
        return (1);
    }
    if (a->size < 5 && a->size != 0)
    {
        free(b.nums);
        return (under6_handler(a, &b));
    }
    if (a->size > 5 && a-> size != 0)
    {
        return (0);
    }
    return (0);
}

/*static void normalize_stack(t_stack *a)
{
}

static void    butterfly_sort(t_stack *a)
{
    normalize_stack(a);
}*/
