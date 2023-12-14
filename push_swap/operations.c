/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglandus <cglandus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:37:25 by cglandus          #+#    #+#             */
/*   Updated: 2023/12/14 20:17:01 by cglandus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    pop(t_stack *a)
{
    int top;

    if (a->size == 0)
        return (0);
    top = a->nums[a->size - 1];
    a->size--;
    return (top);
}

void    swap(t_stack *s, char *mess)
{
    int temp;

    temp = s->nums[s->size - 1];
    s->nums[s->size - 1] = s->nums[s->size - 2];
    s->nums[s->size - 2] = temp;
    ft_putstr_fd(mess, 1);
}

void    push(t_stack *s1, t_stack *s2, char *mess)
{
    int n;

    n = pop(s1);
    s2->size++;
    s2->nums[s2->size - 1] = n;
    ft_putstr_fd(mess, 1);
}

void    rotate(t_stack *s, char *mess)
{
    size_t  i;
    size_t  j;
    int stash;
    int top;

    i = s->size;
    j = i - 2;
    top = s->nums[i - 1];
    while (i > 0)
    {
        stash = s->nums[j];
        s->nums[j] = s->nums[i - 1];
        s->nums[i - 1] = stash;
        i--;
        j--;
    }
    s->nums[0] = top;
    ft_putstr_fd(mess, 1);
}

/*
int main()
{
    t_stack s;
    int i;

    i = 0;
    s.nums = calloc(17 * sizeof(int), 1);
    s.size = 17;
    s.nums[0] = 1;
    s.nums[1] = 2;
    s.nums[2] = 3;
    s.nums[3] = 4;
    s.nums[4] = 5;
    s.nums[5] = 6;
    s.nums[6] = 7;
    s.nums[7] = 8;
    s.nums[8] = 9;
    s.nums[9] = 10;
    s.nums[10] = 11;
    s.nums[11] = 12;
    s.nums[12] = 13;
    s.nums[13] = 14;
    s.nums[14] = 15;
    s.nums[15] = 16;
    s.nums[16] = 17;
    s.nums[17] = 18;
    while (i < 17)
    {
        printf("%d\n", s.nums[i]);
        i++;
    }
    rotate(&s, "\nra\n\n");
    i = 0;
    while (i < 17)
    {
        printf("%d\n", s.nums[i]);
        i++;
    }
    return (0);
}*/