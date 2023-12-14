/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doperations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:50:13 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/14 20:02:19 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ss(t_stack *a, t_stack *b)
{
    swap(a, "s");
    swap(b, "s\n");
}

void    rr(t_stack *a, t_stack *b)
{
    rotate(a, "r");
    rotate(b, "r\n");
}

void    rrab(t_stack *s, char *mess)
{
    size_t  i;
    size_t  j;
    int stash;
    int last;

    i = 0;
    j = i + 1;
    last = s->nums[0];
    while (i < s->size)
    {
        stash = s->nums[j];
        s->nums[j] = s->nums[i];
        s->nums[i] = stash;
        i++;
        j++;
    }
    s->nums[s->size - 1] = last;
    ft_putstr_fd(mess, 1);
}

void    rrr(t_stack *a, t_stack *b)
{
    rrab(a, "rr");
    rrab(b, "r\n");
}
