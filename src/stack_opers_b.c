/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opers_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:56:11 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/23 16:51:00 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements
// Prints sb.
int	sb(t_stacks *x)
{
	int	tmp1;
	int	tmp2;

	if (x->b_len >= 2)
	{
		tmp1 = x->b_stack[0];
		tmp2 = x->b_stack[1];
		x->b_stack[0] = tmp2;
		x->b_stack[1] = tmp1;
		printf("sb\n");
		return (TRUE);
	}
	return (FALSE);
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
// Prints rb.
int	rb(t_stacks *x)
{
	int	tmp1;
	int	tmp2;
	int	i;

	if (x->b_len < 2)
		return (FALSE);
	i = 1;
	if (x->b_len == 2)
	{
		sb(x);
		return (TRUE);
	}
	tmp2 = x->b_stack[x->b_len - (i + 1)];
	x->b_stack[x->b_len - (i + 1)] = x->b_stack[x->b_len - i];
	x->b_stack[x->b_len - i] = x->b_stack[0];
	while (++i + 1 <= x->b_len)
	{
		tmp1 = x->b_stack[x->b_len - (i + 1)];
		x->b_stack[x->b_len - (i + 1)] = tmp2;
		tmp2 = tmp1;
	}
	printf("rb\n");
	return (TRUE);
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
// Prints rrb.
int	rrb(t_stacks *x)
{
	int	tmp1;
	int	tmp2;
	int	i;

	if (x->b_len < 2)
		return (FALSE);
	i = 0;
	tmp1 = x->b_stack[0];
	x->b_stack[0] = x->b_stack[x->b_len - 1];
	while (++i < x->b_len)
	{
		tmp2 = x->b_stack[i];
		x->b_stack[i] = tmp1;
		tmp1 = tmp2;
	}
	printf("rrb\n");
	return (TRUE);
}

//Take the first element at the top of a and put it at the top of b.
//Do nothing if a stack is empty.
//Prints pb.
int	pb(t_stacks *x)
{
	if (x->a_len == 0)
		return (FALSE);
	swaparray(x, B_ID);
	printf("pb\n");
	return (TRUE);
}
