/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:48:08 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/21 20:41:22 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int way_top(t_stacks* a, int index, int id)
{
	if(id == A_ID)
	{
		if(index <= a->a_len - index)
			return(go_r);
		else
			return(go_rr);
	}
	if(id == B_ID)
	{
		if(index <= a->b_len - index)
			return(go_r);
		else
			return(go_rr);
	}
	return(FALSE);
}

int distance_top(t_stacks* a, int index, int id, int dir)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if(id == A_ID)
	{
		if(dir == go_r)
			len = index;
		if(dir == go_rr)
			len = a->a_len - index;
	}
	if(id == B_ID)
	{
		if(dir == go_r)
			len = index;
		if(dir == go_rr)
			len = a->b_len - index;
	}
	return(len);
}

static int distance_bot(t_stacks* a, int index, int id, int dir)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if(id == A_ID)
	{
		if(dir == go_r)
			len = index + 1;
		if(dir == go_rr)
			len = a->a_len - index - 1;
	}
	if(id == B_ID)
	{
		if(dir == go_r)
			len = index + 1;
		if(dir == go_rr)
			len = a->b_len - index - 1;
	}
	return(len);
}

int swap_bigtop(t_stacks* a, int id)
{
	if(id == A_ID)
	{
		if(a->a_len < 2)
			return(FALSE);
		if(a->a_stack[0] < a->a_stack[1])
			sa(a);
	}
	if(id == B_ID)
	{
		if(a->b_len < 2)
			return(FALSE);
		if(a->b_stack[0] < a->b_stack[1])
			sa(a);
	}
	return(TRUE);
}

void makeitgotop(t_stacks* a, int index, int dir, int id)
{
	const int nb = get_nb(a, index, id);
	static int test = 0;
	
	if(id == A_ID)
	{
		if(a->a_len == 1)
			return ; 
		while(index != 0)
		{
			if (dir == go_r)
				ra(a);
			else if(dir == go_rr)
				rra(a);
			index = get_index(a, nb, A_ID);
		}
	}
	if(id == B_ID)
	{
		if(a->b_len == 1)
			return ; 
		while(index != 0)
		{
			if (dir == go_r)
				rb(a);
			else if(dir == go_rr)
				rrb(a);
			index = get_index(a, nb, B_ID);
		}
	}
	test++;
}

int totaldistance(t_stacks* a, int pos_a, int pos_b, int size)
{
	int dis;
	int dis2;
	int dir;
	
	dir = way_top(a, pos_a, A_ID);
	dis = distance_top(a, pos_a, A_ID, dir);
	if(size == BIGGER)
	{
		dir = way_top(a, pos_b, B_ID);
		dis2 = distance_top(a, pos_b, B_ID, dir);
	}
	else
	{
		dir = way_bot(a, pos_b, B_ID);
		dis2 = distance_bot(a, pos_b, B_ID, dir);
	}
	return(dis + dis2);
}
