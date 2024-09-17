/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selango <selango@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-13 13:06:41 by selango           #+#    #+#             */
/*   Updated: 2024-09-13 13:06:41 by selango          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_matrix(char **argv)
{
    int i;
    i = 0;
    if(argv == NULL || *argv == NULL)
        return;
    while (argv[i])
    {
        free(argv[i]);
        i++;
    }
    free(argv);
}


void free_stack(t_stack_node **stack)
{
    t_stack_node *tmp;
    t_stack_node *current;

    if(stack == NULL)
        return;
    current = *stack;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}
void error_free(t_stack_node **a,char **argv,bool flag_argc_2 )
{
    free_stack(a);
    if(flag_argc_2)
    {
           free_matrix(argv);
    } 
    write(1, "Error\n", 6);
    exit(1);
}
int is_digit(char c)
{
    return(c >= '0' && c<= '9');
}

int error_syntax(char *str)
{
    if(!(*str == '+' ||*str == '-' || is_digit(*str) ))
        return(1);
    if((*str == '+' ||*str == '-') && (!is_digit(*str + 1)))
        return(1);
    while (*++str)
    {
        if(!is_digit(*str))
            return(1);
    }
    return(0);
}
int error_repetition(t_stack_node *a,int nbr)
{
    if(NULL == a)
        return(0);
    while(a)
    {
        if(a->value == nbr)
            return(1);
        a = a->next;
    }
    return(0);
}

