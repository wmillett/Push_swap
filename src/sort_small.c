/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:02:48 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/21 15:46:40 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void sort_for3(t_stacks *a, int id)
{
	int big;

	if(id == A_ID)
	{
		big = pos_biggest(a, A_ID);
		if (big == 0 && a->a_len > 2)
			ra(a);
		else if(big == 1 && a->a_len > 2)
			rra(a);
		if(a->a_stack[0] > a->a_stack[1])
			sa(a);
	}
	if(id == B_ID)
	{
		big = pos_biggest(a, B_ID);
		if (big == 0 && a->b_len > 2)
			rb(a);
		else if(big == 1 && a->b_len > 2)
			rrb(a);
		if(a->b_stack[0] > a->b_stack[1])
			sb(a);
	}
}


void sort_for5(t_stacks* a)
{
	const int small = find_smallest(a);
	int next;
	int pos;
	int way;
	
	pos = get_index(a, small, A_ID);
	way = way_top(a, pos, A_ID);
	makeitgotop(a, pos, way, A_ID);
	if(is_sorted(a))
		return ;
	pb(a);
	pos = 0;
	if(a->size == 5)
	{
		next = pos_next(a, pos, B_ID, BIGGER);
		printf("next: %i\n", next);
		way = way_top(a, next, A_ID);
		makeitgotop(a, next, way, A_ID);
		pb(a);
	}
	print_allarray(a);
	sort_for3(a, A_ID);
	if(a->size == 5)
		pa(a);
	pa(a);
}
