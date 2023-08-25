/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lightyagami <lightyagami@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:59:35 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/25 00:06:22 by lightyagami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int calculate_dis(int dis_a1, int dis_a2, int dis_b1, int dis_b2)
{
	int tmp;
	int dir;
	int res;

	res = -1;
	if(dis_a1 <= dis_b2)
		tmp = dis_b2;
	else
		tmp = dis_a1;
	if(dis_a1 + dis_b1 > tmp)
	{
		dir = tmp;
		res = SWITCH_B;
	}
	if(dis_b1 <= dis_a2)
		tmp = dis_a2;
	else
		tmp = dis_b1;
	if(dis_a1 + dis_b1 > tmp)
	{
		if(tmp < res)
		{
			dir = tmp;
			res = SWITCH_A;
		}
	}
	return(res);
}

static int interpret_dir(int to_interpret, int way)
{
	int res;

	if(to_interpret == -1)
		res = way;
	else
	{
		if(to_interpret == SWITCH_A)
		{
			if(way == ONLY_BUP)
				res = BOTH_UP;
			if(way == ONLY_AUP)
				res = BOTH_DW;
		}
		if(to_interpret == SWITCH_B)
		{
			if(way == ONLY_AUP)
				res = BOTH_UP;
			if(way == ONLY_BUP)
				res = BOTH_DW;
		}
	}
	return(res);
}

static int sub_try(t_stacks* a, int pos_b, int size, int dir)
{
	int dis;
	
	if (size == BIGGER)
		dis = distance_top(a, pos_b, B_ID, dir);
	else
		dis = distance_bot(a, pos_b, B_ID, dir);
	return(dis);
}

static int try_ways(t_stacks* a, int pos_a, int pos_b, int size, int way)
{
	int dis_a1;
	int dis_a2;
	int dis_b1;
	int dis_b2;
	int dir_res;
	int res;

	if(way == ONLY_AUP)
	{
		dis_a1 = distance_top(a, pos_a, A_ID, GO_UP);
		dis_a2 = distance_top(a, pos_a, A_ID, GO_DW);
		dis_b1 = sub_try(a, pos_b, size, GO_DW);
		dis_b2 = sub_try(a, pos_b, size, GO_UP);
	}
	else
	{
		dis_a1 = distance_top(a, pos_a, A_ID, GO_DW);
		dis_a2 = distance_top(a, pos_a, A_ID, GO_UP);
		dis_b1 = sub_try(a, pos_b, size, GO_DW);
		dis_b2 = sub_try(a, pos_b, size, GO_UP);
	}
	dir_res = calculate_dis(dis_a1, dis_a2, dis_b1, dis_b2);
	res = interpret_dir(dir_res, way);
	return(res);
}

int compare_way(t_stacks* a, int pos_a, int pos_b, int size)
{
	const int path1 = way_top(a, pos_a, A_ID);
	int path2;
	int way;
	
	if(size == BIGGER)
		path2 = way_top(a, pos_b, B_ID);
	else
		path2 = way_bot(a, pos_b, B_ID);
	if(path1 == path2)
		return(path1);
	if (path1 == GO_UP)
		way = try_ways(a, pos_a, pos_b, size, ONLY_AUP);
	else
		way = try_ways(a, pos_a, pos_b, size, ONLY_BUP);
	return(way);
}












// static int max_move(t_stacks* a, int pos_a, int pos_b, int size)
// {
// 	int dir;
// 	int index;

// 	if (a->a_len == 1)
// 		return ;
// 	while (index != 0)
// 	{
// 		if (dir == GO_R)
// 			ra(a, FALSE);
// 		else if (dir == GO_RR)
// 			rra(a, FALSE);
// 		index = get_index(a, nb, A_ID);
// 	}
// }

void	set_pos(t_stacks *x, int pos_a, int pos_b, int size)
{
	int	dir;

	if (size == BIGGER && x->b_len > 1)
	{
		dir = way_top(x, pos_b, B_ID);
		// makeitgotop(x, pos_b, dir, B_ID);
	}
	if (size == SMALLER && x->b_len > 1)
	{
		dir = way_bot(x, pos_b, B_ID);
		// makeitgobot(x, pos_b, dir, B_ID);
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
