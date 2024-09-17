/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-12 19:01:38 by selango           #+#    #+#             */
/*   Updated: 2024-09-12 19:01:38 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack_node **head)
{
    int len;
    len = stack_len(*head);

    if(*head == NULL || head == NULL || len == 1)
        return;
    *head = (*head)->next;
    (*head)->prev->prev = *head;
    (*head)->prev->next = (*head)->next;
    if((*head)->next)
        (*head)->next->prev = (*head)->prev;
    (*head)->next = (*head)->prev;
    (*head)->prev = NULL; 
}

void sa(t_stack_node ** a,bool checker)
{
    swap(a);
    if(!checker)
        write(1,"sa\n",4);
}
void sb(t_stack_node **b,bool checker)
{
    swap(b);
    if(!checker)
        write(1,"sb\n",4);
}
void ss(t_stack_node **a, t_stack_node **b,bool checker)
{
    swap(a);
    swap(b);
    if(!checker)
        write(1,"ss\n",1);
}
