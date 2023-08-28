/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:43:17 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/27 23:29:58 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void putback(t_stacks* a)
{
	while(a->b_len)
	{
		pa(a);
	}

}

static void radix_loop(t_stacks* a)
{
	int i;
	int bit;
	
	bit = 1;
	while(bit < 4)
	{
		i = 0;
		while(i < a->size)
		{
			if ((a->a_stack[0] >> bit) & 0)
				pb(a);
			else
				ra(a, FALSE);
			i++;
		}
		putback(a);
		bit++;
	}
}





void sort_radix(t_stacks* a)
{
	transform_to_radix(a);
	radix_loop(a);
}