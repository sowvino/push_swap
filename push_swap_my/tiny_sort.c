/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-13 10:59:39 by selango           #+#    #+#             */
/*   Updated: 2024-09-13 10:59:39 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


bool	stack_sorted(t_stack_node *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}


t_stack_node	*find_highest(t_stack_node *stack)
{
	int				highest;
	t_stack_node	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void handle_three(t_stack_node **a)
{
    t_stack_node    *highest_node;

    highest_node = find_highest(*a);
    if(*a == highest_node)
        ra(a,false);
    else if((*a)->next == highest_node)
        rra(a,false);
    if((*a)->value > (*a)->next->value)
        sa(a,false);
}
void sort_stacks(t_stack_node **a,t_stack_node **b)
{
    while (stack_len(*a) > 3)
    {
        init_nodes(*a,*b);
        finish_rotation(a,find_smallest(*a),'a');
        pb(b,a,false);
    }
}

