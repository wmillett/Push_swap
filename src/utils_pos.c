/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:03:36 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/21 18:39:12 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int pos_biggest(t_stacks *a, int id)
{
	int pos;
	int i;
	
	i = 0;
	pos = 0;
	if(id == A_ID)
	{
		while(i < a->a_len)
		{
			if(a->a_stack[i] > a->a_stack[pos])
				pos = i;
			i++;			
		}
	}
	if(id == B_ID)
	{
		while(i < a->b_len)
		{
			if(a->b_stack[i] > a->b_stack[pos])
				pos = i;
			i++;			
		}
	}
	return(pos);
}

int pos_smallest(t_stacks *a, int id)
{
	int pos;
	int i;
	
	i = 0;
	pos = 0;
	if(id == A_ID)
	{
		while(i < a->a_len)
		{
			if(a->a_stack[i] < a->a_stack[pos])
				pos = i;
			i++;			
		}
	}
	if(id == B_ID)
	{
		while(i < a->b_len)
		{
			if(a->b_stack[i] < a->b_stack[pos])
				pos = i;
			i++;			
		}
	}
	return(pos);
}

int closest_totop(t_stacks* a, int pos1, int pos2, int id)
{
	const int path1 = way_top(a, pos1, id);
	const int path2 = way_top(a, pos2, id);
	int dis1;
	int dis2;
	
	if(id == A_ID)
	{
		if(a->a_len < 2)
			return(INVALID);
		dis1 = distance_top(a, pos1, A_ID, path1);
		dis2 = distance_top(a, pos2, A_ID, path2);
	}
	if(id == B_ID)
	{
		if(a->b_len < 2)
			return(INVALID);
		dis1 = distance_top(a, pos1, B_ID, path1);
		dis2 = distance_top(a, pos2, B_ID, path2);
	}
	if(dis1 < dis2)
		return(1);
	else if(dis1 > dis2)
		return(2);
	else
		return(0);
}
