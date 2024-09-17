/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-12 18:23:07 by selango           #+#    #+#             */
/*   Updated: 2024-09-12 18:23:07 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack_node **stack)
{
    t_stack_node *last;
    int len;

    len = stack_len(*stack);
    if(*stack == NULL || stack == NULL || len == 1)
        return;
    last = find_last(*stack);
    last->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last->next->prev = last;
    last->next->next =NULL;
}
void ra(t_stack_node **a,bool checker)
{
    rotate(a);
     if(!checker)
        write(1,"ra\n",4);
}
void rb(t_stack_node **b,bool checker)
{
    rotate(b);
     if(!checker)
        write(1,"rb\n",4);
}
void rr(t_stack_node **a,t_stack_node **b,bool checker)
{
    rotate(a);
    rotate(b);
    if(!checker)
        write(1,"rr\n",4);
}
