/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:59:35 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/24 18:28:21 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"





static int calculate_dis(t_stacks* a, int dis_a1, int dis_a2, int dis_b1, int dis_b2)
{
	int tmp;
	int res;

	if(dis_a1 <= dis_b2)
		tmp = dis_b2 - dis_a1;
	else
		tmp = dis_a1 - dis_b2;
	
	
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
	int dis_res;

	if(way == ONLY_AUP)
	{
		dis_a1 = distance_top(a, pos_a, A_ID, GO_UP);
		dis_a2 = distance_top(a, pos_a, A_ID, GO_DW);
		dis_b1 = sub_try(a, pos_b, B_ID, GO_DW);
		dis_b2 = sub_try(a, pos_b, B_ID, GO_UP);
	}
	else
	{
		dis_a1 = distance_top(a, pos_a, A_ID, GO_DW);
		dis_a2 = distance_top(a, pos_a, A_ID, GO_UP);
		dis_b1 = sub_try(a, pos_b, B_ID, GO_DW);
		dis_b2 = sub_try(a, pos_b, B_ID, GO_UP);
	}
	dis_res = calculate_dis(a, dis_a1, dis_a2, dis_b1, dis_b2);
	return(dis_res);
}




int compare_way(t_stacks* a, int pos_a, int pos_b, int size)
{
	const int path1 = way_top(a, pos_a, A_ID);
	int path2;
	int dis1;
	int dis2;
	int tmp;
	
	if(size == BIGGER)
		path2 = way_top(a, pos_b, B_ID);
	else
		path2 = way_bot(a, pos_b, B_ID);
	// dis1 = distance_top(a, pos_a, A_ID, path1);
	if(path1 == path2)
		return(path1);
	if (path1 == GO_UP)
		tmp = try_ways(a, pos_a, pos_b, size, ONLY_AUP);
	else
		tmp = try_ways(a, pos_a, pos_b, size, ONLY_BUP);
	// if(size == BIGGER)
	// 	dis2 = distance_top(a, pos_b, B_ID, path2);
	// else
	// 	dis2 = distance_bot(a, pos_b, B_ID, path2);
	// if(dis1 > dis2 && dis)
		

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
