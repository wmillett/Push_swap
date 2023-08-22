/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:38:53 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/21 18:55:32 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int check_A(t_stacks* a, int index, int pos)
{
	int i;
	int check;

	i = 0;
	check = INVALID;
	while(i < a->a_len)
	{
		if(a->a_stack[i] > a->b_stack[index] && a->a_stack[i] < a->b_stack[pos])
		{
			check = i;
			break ;
		}
		i++;
	}
	return(check);
}

static int get_big_A(t_stacks* a, int index, int pos)
{
	int i;
	
	i = 0;
	while(i < a->a_len)
	{
		if(a->a_stack[i] > a->b_stack[index] && a->a_stack[i] < a->a_stack[pos])
			pos = i;
		i++;
	}
	i = 0;
	while(i < a->b_len)
	{
		if(a->a_stack[i] > a->b_stack[index] && a->a_stack[i] < a->a_stack[pos])
			return(INVALID);
		i++;
	}
	return(pos);
}

static int get_big_B(t_stacks* a, int index, int pos)
{
	int i;
	int res;

	i = 0;
	while(i < a->b_len)
	{
		if(a->b_stack[i] > a->b_stack[index] && a->b_stack[i] < a->b_stack[pos])
			pos = i;
		i++;
	}

	res = check_A(a, index, pos);
	if(res == INVALID)
		return(INVALID);
	i = 0;
	while(i < a->a_len)
	{
		if(a->a_stack[i] > a->b_stack[index] && a->a_stack[i] < a->a_stack[res])
			res = i;
		i++;
	}
	return(res);
}

int find_next(t_stacks* a, int id, int index)
{
	const int big = find_biggest(a);
	int pos;
	int nbid;

	(void)id;
	nbid = find_id(a, big);
	pos = get_index(a, big, nbid);
	if(nbid == A_ID)
		pos = get_big_A(a, index, pos);
	else
		pos = get_big_B(a, index, pos);
	return(pos);
}
