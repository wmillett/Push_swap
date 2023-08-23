/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:59:35 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/23 16:48:25 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_pos(t_stacks *x, int pos_a, int pos_b, int size)
{
	int	dir;

	if (size == BIGGER && x->b_len > 1)
	{
		dir = way_top(x, pos_b, B_ID);
		makeitgotop(x, pos_b, dir, B_ID);
	}
	if (size == SMALLER && x->b_len > 1)
	{
		dir = way_bot(x, pos_b, B_ID);
		makeitgobot(x, pos_b, dir, B_ID);
	}
	if (x->a_len > 1)
	{
		dir = way_top(x, pos_a, A_ID);
		makeitgotop(x, pos_a, dir, A_ID);
	}
}

int	compare_distance(t_stacks *a, int nbx, int small, int big)
{
	int	dis1;
	int	dis2;

	dis1 = totaldistance(a, small, nbx, SMALLER);
	dis2 = totaldistance(a, big, nbx, BIGGER);
	if (dis1 == dis2)
		return (EQUAL);
	if (dis1 < dis2)
		return (SMALLER);
	else
		return (BIGGER);
}
