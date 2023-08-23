/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:57:24 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/23 16:47:16 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	removetop(int *stack, int len)
{
	int	i;

	i = 0;
	if (len == 1)
		return (TRUE);
	if (len == 0)
		return (FALSE);
	while (i + 1 < len)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	return (TRUE);
}

static int	addtop(int *stack, int len, int toadd)
{
	int	size;

	if (len == 0)
	{
		stack[0] = toadd;
		return (TRUE);
	}
	size = len;
	while (size - 1 >= 0)
	{
		stack[size] = stack[size - 1];
		size--;
	}
	stack[0] = toadd;
	return (TRUE);
}

void	swaparray(t_stacks *x, int id)
{
	if (id == A_ID)
	{
		addtop(x->a_stack, x->a_len, x->b_stack[0]);
		x->a_len++;
		removetop(x->b_stack, x->b_len);
		x->b_len--;
	}
	if (id == B_ID)
	{
		addtop(x->b_stack, x->b_len, x->a_stack[0]);
		x->b_len++;
		removetop(x->a_stack, x->a_len);
		x->a_len--;
	}
}
