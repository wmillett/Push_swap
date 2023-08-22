/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:13:47 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/21 22:09:59 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int pos_next(t_stacks* a, int index, int id, int size)
{
	const int big = find_biggest(a);
	const int small = find_smallest(a);
	int pos;
	
	if(size == BIGGER && a->b_stack[index] == big) 
		return(INVALID);
	if (size == SMALLER && a->b_stack[index] == small)
		return(INVALID);
	if(size == BIGGER)
		pos = find_next(a, id, index);
	else
		pos = find_nextsmall(a, id, index);
	return(pos);
}

int get_next(t_stacks* a, int index, int id, int rt_value)
{
	int small;
	int big;
	int dir;
	int dis;

	small = pos_next(a, index, id, SMALLER);
	big = pos_next(a, index, id, BIGGER);
	if(small <= INVALID && big <= INVALID)
		return(INVALID);
	else if(small <= INVALID && big > INVALID)
		dir = BIGGER;
	else if(small > INVALID && big <= INVALID)
		dir = SMALLER;
	else
		dir = compare_distance(a, index, small, big);
	if(dir == SMALLER || dir == EQUAL)
		dis = totaldistance(a, small, index, SMALLER);
	if(dir == BIGGER)
		dis = totaldistance(a, big, index, BIGGER);
	if(rt_value == TRUE)
	{
		if(dir == SMALLER)
			return(small);
		if(dir == BIGGER || dir == EQUAL)
			return(big);
	}
	return(dis);
}

int least_moves(t_stacks* a, int id)
{
	int dis;
	int i;
	int shortest;
	int pos_b;
	int pos_a;

	shortest = -2;
	i = 0;
	while(i < a->b_len)
	{
		dis = get_next(a, i, B_ID, FALSE);
		if((dis < shortest || shortest == -2) && !(dis < 0))
		{
			pos_b = i;
			shortest = dis;
		}
		i++;
	}
	if(id == B_ID)
		return(pos_b);
	pos_a = get_next(a, pos_b, B_ID, TRUE);
	return(pos_a);
}

static void setup_start(t_stacks* a)
{
	if(is_sorted(a))
		leave(a);
	pb(a);
}

static void setup_loop(t_stacks* a, int size)
{
	pb(a);
	if(size == SMALLER)
		rb(a);
}
void sortforbig(t_stacks* x)
{
	int pos_b;
	int pos_a;
	int size;

	size = 0;
	pos_a = 0;
	pos_b = 0;
	setup_start(x);
	while(x->a_len != 0)
	{
		pos_b = least_moves(x, B_ID);
		pos_a = least_moves(x, A_ID);
		if(pos_a == INVALID || pos_b == INVALID)
			break ;
		if(x->a_stack[pos_a] > x->b_stack[pos_b])
			size = BIGGER;
		else
			size = SMALLER;
		set_pos(x, pos_a, pos_b, size);
		setup_loop(x, size);
	}
	makebigtop(x, B_ID);
	while(x->b_len != 0)
		pa(x);
}

void sort_method(t_stacks *a)
{
	a->a_len = a->size;
	a->b_len = 0;
	print_allarray(a);
	if (a->size <= 3)
		sort_for3(a, A_ID);
	else if(a->size <= 5)
		sort_for5(a);
	else
		sortforbig(a);
	print_allarray(a);
	return ;
}
