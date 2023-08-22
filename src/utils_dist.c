/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 04:04:38 by lightyagami       #+#    #+#             */
/*   Updated: 2023/08/21 18:22:27 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void makebigtop(t_stacks* x, int id)
{
	int big;
	int pos;
	int way;
	
	if(id == A_ID)
	{
		big = find_biggest(x);
		pos = get_index(x, big, A_ID);
		way = way_top(x, pos, A_ID);
		makeitgotop(x, pos, way, A_ID);
	}
	if(id == B_ID)
	{
		big = find_biggest(x);
		pos = get_index(x, big, B_ID);
		way = way_top(x, pos, B_ID);
		makeitgotop(x, pos, way, B_ID);
	}
}

int way_bot(t_stacks* a, int index, int id)
{
   if(id == A_ID)
	{
		if(index < a->a_len - index)
			return(go_r);
		else
			return(go_rr);
	}
	if(id == B_ID)
	{
		if(index < a->b_len - index)
			return(go_r);
		else
			return(go_rr);
	}
	return(FALSE);
}

void makeitgobot(t_stacks* a, int index, int dir, int id)
{
	int nb;
	int tmp;
	static int test = 0;
	
	nb = get_nb(a, index, id);
	if(id == A_ID)
	{
		while(index != a->a_len - 1)
		{
			if (dir == go_r)
				ra(a);
			else if(dir == go_rr)
				rra(a);
			index = get_index(a, nb, id);
		}
	}
	if(id == B_ID)
	{
		tmp = index;
		while(tmp != a->b_len - 1)
		{
			printf("test: %i\n", test);
			if (dir == go_r)
				rb(a);
			else if(dir == go_rr)
				rrb(a);
			tmp = get_index(a, nb, id);
		}
	}
	test++;
}
