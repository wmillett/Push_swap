/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 04:04:38 by lightyagami       #+#    #+#             */
/*   Updated: 2023/08/24 15:36:14 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	makebigtop(t_stacks *x, int id)
{
	int	big;
	int	pos;
	int	way;

	if (id == A_ID)
	{
		big = find_biggest(x);
		pos = get_index(x, big, A_ID);
		way = way_top(x, pos, A_ID);
		makeitgotop(x, pos, way, A_ID);
	}
	if (id == B_ID)
	{
		big = find_biggest(x);
		pos = get_index(x, big, B_ID);
		way = way_top(x, pos, B_ID);
		makeitgotop(x, pos, way, B_ID);
	}
}

int	way_bot(t_stacks *a, int index, int id)
{
	if (id == A_ID)
	{
		if (index < a->a_len - index)
			return (GO_R);
		else
			return (GO_RR);
	}
	if (id == B_ID)
	{
		if (index < a->b_len - index)
			return (GO_R);
		else
			return (GO_RR);
	}
	return (FALSE);
}

void	makeitgobot(t_stacks *a, int index, int dir, int id)
{
	const int	nb = get_nb(a, index, id);
	int			tmp;

	if (id == A_ID)
	{
		while (index != a->a_len - 1)
		{
			if (dir == GO_R)
				ra(a, FALSE);
			else if (dir == GO_RR)
				rra(a, FALSE);
			index = get_index(a, nb, id);
		}
		return ;
	}
	tmp = index;
	while (tmp != a->b_len - 1)
	{
		if (dir == GO_R)
			rb(a, FALSE);
		else if (dir == GO_RR)
			rrb(a, FALSE);
		tmp = get_index(a, nb, id);
	}
}

int	totaldistance(t_stacks *a, int pos_a, int pos_b, int size)
{
	int	dis;
	int	dis2;
	int	dir;

	dir = way_top(a, pos_a, A_ID);
	dis = distance_top(a, pos_a, A_ID, dir);
	if (size == BIGGER)
	{
		dir = way_top(a, pos_b, B_ID);
		dis2 = distance_top(a, pos_b, B_ID, dir);
	}
	else
	{
		dir = way_bot(a, pos_b, B_ID);
		dis2 = distance_bot(a, pos_b, B_ID, dir);
	}
	return (dis + dis2);
}
