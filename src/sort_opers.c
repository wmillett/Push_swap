/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lightyagami <lightyagami@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:59:35 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/27 04:15:46 by lightyagami      ###   ########.fr       */
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

int best_distance(t_stacks* a, int pos_a, int pos_b, int size)
{
	const int way = compare_way(a, pos_a, pos_b, size);
	int res;
	int dis1;
	int dis2;
	
	if(way == BOTH_UP || way == ONLY_AUP)
		dis1 = distance_top (a, pos_a, A_ID, BOTH_UP);
	else
		dis1 = distance_top(a, pos_a, A_ID, BOTH_DW);
	if((way == BOTH_UP || way == ONLY_BUP) && size == BIGGER)
		dis2 = distance_top(a, pos_b, B_ID, BOTH_UP);
	else if ((way == BOTH_UP || way == ONLY_BUP) && size == SMALLER)
		dis2 = distance_bot(a, pos_b, B_ID, BOTH_UP);
	else if ((way == BOTH_DW || way == ONLY_AUP) && size == BIGGER)
		dis2 = distance_top(a, pos_b, B_ID, BOTH_DW);
	else if ((way == BOTH_DW || way == ONLY_AUP) && size == SMALLER)
		dis2 = distance_bot(a, pos_b, B_ID, BOTH_DW);
	else 
		return(INVALID);
	res = (dis1 + dis2);
	return(res);
}



// int find_best_distance(t_stacks* a, )
// {

	
// }


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

static void count_way(t_stacks* a, int pos_a, int pos_b, int size, int way)
{
	const int nb_a = get_nb(a, pos_a, A_ID);
	const int nb_b = get_nb(a, pos_b, B_ID);
	int i;
	int pos1;
	int pos2;
	
	if(a->b_len <= 1 || a->a_len <= 1)
		return ;
	i = 0;
	pos1 = -1;
	pos2 = -1;
	while(1)
	{
		if(way == BOTH_UP)
			rr(a);
		if(way == BOTH_DW)
			rrr(a);
		pos1 = get_index(a, nb_a, A_ID);
		pos2 = get_index(a, nb_b, B_ID);
		if((pos1 == 0 || pos2 == 0) && size == BIGGER)
			break ;
		if ((pos1 == 0 || pos2 == a->b_len - 1) && size == SMALLER)
			break ;
	}
}



static void solve_remain(t_stacks* a, int pos_a, int pos_b, int size, int way)
{
	if(pos_a == 0)
	{
		if(size == BIGGER)
			makeitgotop(a, pos_b, way, B_ID);
		if(size == SMALLER)
			makeitgobot(a, pos_b, way, B_ID);
	}
	else
		makeitgotop(a, pos_a, way, A_ID);
}

static void makeitgo(t_stacks* a, int pos_a, int pos_b, int size, int way)
{
	if (way == ONLY_AUP)
		makeitgotop(a, pos_a, GO_UP, A_ID);
	else
		makeitgotop(a, pos_a, GO_DW, A_ID);
	if (size == BIGGER)
	{
		if(way == ONLY_AUP)
			makeitgotop(a, pos_b, GO_DW, B_ID);
		else
			makeitgotop(a, pos_b, GO_UP, B_ID);
	}
	else
	{
		if(way == ONLY_AUP)
			makeitgobot(a, pos_b, GO_DW, B_ID);
		else
			makeitgobot(a, pos_b, GO_UP, B_ID);
	}
}


void	set_pos(t_stacks *x, int pos_a, int pos_b, int size)
{
	const int way = compare_way(x, pos_a, pos_b, size);
	const int nb_a = get_nb(x, pos_a, A_ID);
	const int nb_b = get_nb(x, pos_b, B_ID);
	
	if(way == BOTH_UP || way == BOTH_DW)
	{
		count_way(x, pos_a, pos_b, size, way);
		pos_a = get_index(x, nb_a, A_ID);
		pos_b = get_index(x, nb_b, B_ID);
		solve_remain(x, pos_a, pos_b, size, way);
	}
	else
		makeitgo(x, pos_a, pos_b, size, way);
}

int	compare_distance(t_stacks *a, int nbx, int small, int big)
{
	int	dis1;
	int	dis2;

	dis1 = best_distance(a, small, nbx, SMALLER);
	dis2 = best_distance(a, big, nbx, BIGGER);
	if (dis1 == dis2)
		return (EQUAL);
	if (dis1 < dis2)
		return (SMALLER);
	else
		return (BIGGER);
}
