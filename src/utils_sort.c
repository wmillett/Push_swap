/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:48:08 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/23 17:28:39 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	way_top(t_stacks *a, int index, int id)
{
	if (id == A_ID)
	{
		if (index <= a->a_len - index)
			return (GO_R);
		else
			return (GO_RR);
	}
	if (id == B_ID)
	{
		if (index <= a->b_len - index)
			return (GO_R);
		else
			return (GO_RR);
	}
	return (FALSE);
}

int	distance_top(t_stacks *a, int index, int id, int dir)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (id == A_ID)
	{
		if (dir == GO_R)
			len = index;
		if (dir == GO_RR)
			len = a->a_len - index;
	}
	if (id == B_ID)
	{
		if (dir == GO_R)
			len = index;
		if (dir == GO_RR)
			len = a->b_len - index;
	}
	return (len);
}

int	distance_bot(t_stacks *a, int index, int id, int dir)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (id == A_ID)
	{
		if (dir == GO_R)
			len = index + 1;
		if (dir == GO_RR)
			len = a->a_len - index - 1;
	}
	if (id == B_ID)
	{
		if (dir == GO_R)
			len = index + 1;
		if (dir == GO_RR)
			len = a->b_len - index - 1;
	}
	return (len);
}

int	swap_bigtop(t_stacks *a, int id)
{
	if (id == A_ID)
	{
		if (a->a_len < 2)
			return (FALSE);
		if (a->a_stack[0] < a->a_stack[1])
			sa(a);
	}
	if (id == B_ID)
	{
		if (a->b_len < 2)
			return (FALSE);
		if (a->b_stack[0] < a->b_stack[1])
			sa(a);
	}
	return (TRUE);
}

void	makeitgotop(t_stacks *a, int index, int dir, int id)
{
	const int	nb = get_nb(a, index, id);

	if (id == A_ID)
	{
		if (a->a_len == 1)
			return ;
		while (index != 0)
		{
			if (dir == GO_R)
				ra(a);
			else if (dir == GO_RR)
				rra(a);
			index = get_index(a, nb, A_ID);
		}
	}
	if (a->b_len == 1 || id == A_ID)
		return ;
	while (index != 0)
	{
		if (dir == GO_R)
			rb(a);
		else if (dir == GO_RR)
			rrb(a);
		index = get_index(a, nb, B_ID);
	}
}
