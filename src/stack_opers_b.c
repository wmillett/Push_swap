/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opers_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:56:11 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/21 18:21:18 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements
// Prints sb.
int sb(t_stacks *x)
{
	int tmp1;
	int tmp2;
	
	if (x->b_len >= 2)
	{
		tmp1 = x->b_stack[0];
		tmp2 = x->b_stack[1];
		x->b_stack[0] = tmp2;
		x->b_stack[1] = tmp1;
		printf("sb\n");
		return(TRUE);
	}
	return(FALSE);
}

// Shift up all elements of stack b by 1.
// The first element becomes the last one.
// Prints rb.
int rb(t_stacks *x)
{
    int tmp1;
    int tmp2;
    int i;

	if(x->b_len < 2)
		return(FALSE);
    i = 1;
	if(x->b_len == 2)
	{
		sb(x);
		return(TRUE);
	}
    tmp2 = x->b_stack[x->b_len - (i + 1)];
    x->b_stack[x->b_len - (i + 1)] = x->b_stack[x->b_len - i];
    x->b_stack[x->b_len - i] = x->b_stack[0];
    while(++i + 1 <= x->b_len)
    {
        tmp1 = x->b_stack[x->b_len - (i + 1)];
        x->b_stack[x->b_len - (i + 1)] = tmp2;
        tmp2 = tmp1;
    }
	printf("rb\n");
    return(TRUE);
}

// Shift down all elements of stack b by 1.
// The last element becomes the first one.
// Prints rrb.
int rrb(t_stacks *x)
{
    int tmp1;
    int tmp2;
    int i;

	if(x->b_len < 2)
		return(FALSE);
    i = 0;
    tmp1 = x->b_stack[0];
	x->b_stack[0] = x->b_stack[x->b_len - 1];
	while(++i < x->b_len)
	{
		tmp2 = x->b_stack[i];
		x->b_stack[i] = tmp1;
		tmp1 = tmp2;
	}
	printf("rrb\n");
    return(TRUE);
}

//Take the first element at the top of a and put it at the top of b.
//Do nothing if a stack is empty.
//Prints pb.
int pb(t_stacks *x)
{
	if(x->a_len == 0)
		return(FALSE);
	swaparray(x, B_ID);
	printf("pb\n");
	return(TRUE);
}







































// // Swap the first 2 elements at the top of stack a.
// // Do nothing if there is only one or no elements
// // Prints sa for a_stack and sb for b_stack.
// int sa_sb(t_stacks *x, int id)
// {
// 	int tmp1;
// 	int tmp2;
	
// 	if (x->size >= 2)
// 	{
// 		tmp1 = x->stack[0];
// 		tmp2 = x->stack[1];
// 		x->stack[0] = tmp2;
// 		x->stack[1] = tmp1;
// 		if (id == A_ID)
// 			printf("sa\n");
// 		if (id == B_ID)
// 			printf("sb\n");
// 		return(TRUE);
// 	}
// 	return(FALSE);
// }

// // Shift up all elements of stack 'X' by 1.
// // The first element becomes the last one.
// // Prints ra for a_stack and rb for b_stack.
// int ra_rb(t_stack *x, int id)
// {
//     int tmp1;
//     int tmp2;
//     int i;

//     i = 1;
//     tmp2 = x->stack[x->size - (i + 1)];
//     x->stack[x->size - (i + 1)] = x->stack[x->size - i];
//     x->stack[x->size - i] = x->stack[0];
//     while(++i + 1 <= x->size)
//     {
//         tmp1 = x->stack[x->size - (i + 1)];
//         x->stack[x->size - (i + 1)] = tmp2;
//         tmp2 = tmp1;
//     }
// 	if (id == A_ID)
// 		printf("ra\n");
// 	else if (id == B_ID)
// 		printf("rb\n");
// 	else
// 		return(FALSE);
//     return(TRUE);
// }

// // Shift down all elements of stack 'X' by 1.
// // The last element becomes the first one.
// // Prints rra for a_stack and rrb for b_stack.
// int rra_rrb(t_stack *x, int id)
// {
//     int tmp1;
//     int tmp2;
//     int i;

//     i = 0;
//     tmp1 = x->stack[0];
// 	x->stack[0] = x->stack[x->size - 1];
// 	while(++i < x->size)
// 	{
// 		tmp2 = x->stack[i];
// 		x->stack[i] = tmp1;
// 		tmp1 = tmp2;
// 	}
// 	if (id == A_ID)
// 		printf("rra\n");
// 	else if (id == B_ID)
// 		printf("rrb\n");
// 	else
// 		return(FALSE);
//     return(TRUE);
// }

// //Take the first element at the top of a or b and put it at the top of the other.
// //Do nothing if the original stack is empty.
// //Prints pa for b to a and pb for a to b.
// // int pa_pb(t_stack *topushto, t_stack *topushfrom, int id)
// // {
	

	

	
// // 	if (id == A_ID)
// // 		printf("pa\n");
// // 	else if (id == B_ID)
// // 		printf("pb\n");
// // 	else
// // 		return(FALSE);
// // 	return(TRUE);
// // }