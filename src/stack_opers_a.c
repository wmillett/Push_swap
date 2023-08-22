/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opers_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:56:11 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/16 19:11:32 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements
// Prints sa.
int sa(t_stacks *x)
{
	int tmp1;
	int tmp2;
	
	if (x->a_len >= 2)
	{
		tmp1 = x->a_stack[0];
		tmp2 = x->a_stack[1];
		x->a_stack[0] = tmp2;
		x->a_stack[1] = tmp1;
		printf("sa\n");
		return(TRUE);
	}
	return(FALSE);
}

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
// Prints ra.
int ra(t_stacks *x)
{
    int tmp1;
    int tmp2;
    int i;

	if(x->a_len < 2)
		return(FALSE);
	if(x->a_len == 2)
	{
		sa(x);
		return(TRUE);
	}
    i = 1;
    tmp2 = x->a_stack[x->a_len - (i + 1)];
    x->a_stack[x->a_len - (i + 1)] = x->a_stack[x->a_len - i];
    x->a_stack[x->a_len - i] = x->a_stack[0];
    while(++i + 1 <= x->a_len)
    {
        tmp1 = x->a_stack[x->a_len - (i + 1)];
        x->a_stack[x->a_len - (i + 1)] = tmp2;
        tmp2 = tmp1;
    }
	printf("ra\n");
    return(TRUE);
}

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
// Prints rra.
int rra(t_stacks *x)
{
    int tmp1;
    int tmp2;
    int i;

	if(x->a_len < 2)
		return(FALSE);
    i = 0;
    tmp1 = x->a_stack[0];
	x->a_stack[0] = x->a_stack[x->a_len - 1];
	while(++i < x->a_len)
	{
		tmp2 = x->a_stack[i];
		x->a_stack[i] = tmp1;
		tmp1 = tmp2;
	}
	printf("rra\n");
    return(TRUE);
}

//Take the first element at the top of b and put it at the top of a.
//Do nothing if b stack is empty.
//Prints pa.
int pa(t_stacks *x)
{
	if(x->b_len == 0)
		return(FALSE);
	swaparray(x, A_ID);
	printf("pa\n");
	return(TRUE);
}
