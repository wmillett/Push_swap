/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:13:47 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/27 19:52:47 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_next(t_stacks *a, int index, int id, int rt_value)
{
	const int	small = pos_next(a, index, id, SMALLER);
	const int	big = pos_next(a, index, id, BIGGER);
	int			dir;
	int			dis;

	if (small <= INVALID && big <= INVALID)
		return (INVALID);
	else if (small <= INVALID && big > INVALID)
		dir = BIGGER;
	else if (small > INVALID && big <= INVALID)
		dir = SMALLER;
	else
		dir = compare_distance(a, index, small, big);
	if (dir == SMALLER)
		dis = best_distance(a, small, index, SMALLER);
		// dis = totaldistance(a, small, index, SMALLER);
	if (dir == BIGGER || dir == EQUAL)
		dis = best_distance(a, big, index, BIGGER);
		// dis = totaldistance(a, big, index, BIGGER);
	if (rt_value == TRUE)
	{
		if (dir == SMALLER)
			return (small);
		if (dir == BIGGER || dir == EQUAL)
			return (big);
	}
	return (dis);
}

int	least_moves(t_stacks *a, int id)
{
	int	dis;
	int	i;
	int	shortest;
	int	pos_b;
	int	pos_a;

	shortest = -2;
	i = 0;
	while (i < a->b_len)
	{
		dis = get_next(a, i, B_ID, FALSE);
		// dis = best_distance(a, );
		if ((dis < shortest || shortest == -2) && !(dis < 0))
		{
			pos_b = i;
			shortest = dis;
		}
		i++;
	}
	if (id == B_ID)
		return (pos_b);
	pos_a = get_next(a, pos_b, B_ID, TRUE);
	return (pos_a);
}

static void	setup_start(t_stacks *a)
{
	if (is_sorted(a))
		leave(a);
	pb(a);
	// pb(a);
	// if (a->b_stack[0] < a->b_stack[1])
	// 	sb(a, FALSE);
}

static void	setup_loop(t_stacks *a, int size)
{
	pb(a);
	if (size == SMALLER)
		rb(a, FALSE);
}

void	sortforbig(t_stacks *x)
{
	int	pos_b;
	int	pos_a;
	int	size;

	size = 0;
	pos_a = 0;
	pos_b = 0;
	setup_start(x);
	while (x->a_len != 0)
	{
		pos_b = least_moves(x, B_ID);
		pos_a = least_moves(x, A_ID);
		if (pos_a == INVALID || pos_b == INVALID)
			break ;
		if (x->a_stack[pos_a] > x->b_stack[pos_b])
			size = BIGGER;
		else
			size = SMALLER;
		set_pos(x, pos_a, pos_b, size);
		setup_loop(x, size);
	}
	makebigtop(x, B_ID);
	while (x->b_len != 0)
		pa(x);
}
