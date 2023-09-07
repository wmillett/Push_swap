/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:03:36 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/29 16:49:28 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	pos_next(t_stacks *a, int index, int id, int size)
{
	const int	big = find_biggest(a);
	const int	small = find_smallest(a);
	int			pos;

	if (size == BIGGER && a->b_stack[index] == big)
		return (INVALID);
	if (size == SMALLER && a->b_stack[index] == small)
		return (INVALID);
	if (size == BIGGER)
		pos = find_next(a, id, index);
	else
		pos = find_nextsmall(a, id, index);
	return (pos);
}

int	pos_biggest(t_stacks *a, int id)
{
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	if (id == A_ID)
	{
		while (i < a->a_len)
		{
			if (a->a_stack[i] > a->a_stack[pos])
				pos = i;
			i++;
		}
	}
	if (id == B_ID)
	{
		while (i < a->b_len)
		{
			if (a->b_stack[i] > a->b_stack[pos])
				pos = i;
			i++;
		}
	}
	return (pos);
}

int	pos_smallest(t_stacks *a, int id)
{
	int	pos;
	int	i;

	i = 0;
	pos = 0;
	if (id == A_ID)
	{
		while (i < a->a_len)
		{
			if (a->a_stack[i] < a->a_stack[pos])
				pos = i;
			i++;
		}
	}
	if (id == B_ID)
	{
		while (i < a->b_len)
		{
			if (a->b_stack[i] < a->b_stack[pos])
				pos = i;
			i++;
		}
	}
	return (pos);
}

// int	closest_totop(t_stacks *a, int pos1, int pos2, int id)
// {
// 	const int	path1 = way_top(a, pos1, id);
// 	const int	path2 = way_top(a, pos2, id);
// 	int			dis1;
// 	int			dis2;

// 	if (id == A_ID)
// 	{
// 		if (a->a_len < 2)
// 			return (INVALID);
// 		dis1 = distance_top(a, pos1, A_ID, path1);
// 		dis2 = distance_top(a, pos2, A_ID, path2);
// 	}
// 	if (id == B_ID)
// 	{
// 		if (a->b_len < 2)
// 			return (INVALID);
// 		dis1 = distance_top(a, pos1, B_ID, path1);
// 		dis2 = distance_top(a, pos2, B_ID, path2);
// 	}
// 	if (dis1 < dis2)
// 		return (1);
// 	else if (dis1 > dis2)
// 		return (2);
// 	else
// 		return (0);
// }

// int	best_distance(t_stacks *a, int pos_a, int pos_b, int size)
// {
// 	const int	way = compare_way(a, pos_a, pos_b, size);
// 	int			res;
// 	int			dis1;
// 	int			dis2;

// 	if (way == BOTH_UP || way == ONLY_AUP)
// 		dis1 = distance_top(a, pos_a, A_ID, BOTH_UP);
// 	else
// 		dis1 = distance_top(a, pos_a, A_ID, BOTH_DW);
// 	if ((way == BOTH_UP || way == ONLY_BUP) && size == BIGGER)
// 		dis2 = distance_top(a, pos_b, B_ID, BOTH_UP);
// 	else if ((way == BOTH_UP || way == ONLY_BUP) && size == SMALLER)
// 		dis2 = distance_bot(a, pos_b, B_ID, BOTH_UP);
// 	else if ((way == BOTH_DW || way == ONLY_AUP) && size == BIGGER)
// 		dis2 = distance_top(a, pos_b, B_ID, BOTH_DW);
// 	else if ((way == BOTH_DW || way == ONLY_AUP) && size == SMALLER)
// 		dis2 = distance_bot(a, pos_b, B_ID, BOTH_DW);
// 	else
// 		return (INVALID);
// 	res = (dis1 + dis2);
// 	return (res);
// }
