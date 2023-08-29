/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:43:17 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/29 16:14:49 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	get_max_bits(t_stacks *a)
{
	int	max;
	int	max_bits;
	int	i;

	max_bits = 0;
	max = a->a_stack[0];
	i = 1;
	while (i < a->size)
	{
		if (a->a_stack[i] > max)
			max = a->a_stack[i];
		i++;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	putback(t_stacks *a)
{
	while (a->b_len)
	{
		pa(a);
	}
}

static void	radix_loop(t_stacks *a)
{
	int	i;
	int	j;
	int	bit;

	j = 0;
	bit = get_max_bits(a);
	while (j < bit)
	{
		i = 0;
		while (i < a->size)
		{
			if (((a->a_stack[0] >> j) & 1) == 1)
				ra(a, FALSE);
			else
				pb(a);
			i++;
		}
		putback(a);
		j++;
	}
}

void	sort_radix(t_stacks *a)
{
	transform_to_radix(a);
	radix_loop(a);
}
