/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:54:58 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/21 18:25:30 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int find_index(t_stacks* a, int nb)
{
	int i;
	int pos;

	i = 0;
	while(i < a->a_len)
	{
		if(a->a_stack[i] == nb)
			pos = i;
		i++;		
	}
	i = 0;
	while(i < a->b_len)
	{
		if(a->b_stack[i] == nb)
			pos = i;
		i++;	
	}
	return(pos);
}




int get_index(t_stacks* a, int nb, int id)
{
	int index;
	int i;
	
	i = 0;
	index = -1;
	i = 0;
	if(id == A_ID)	
	{
		while(i < a->a_len)
		{
			if(a->a_stack[i] == nb)
				index = i;
			i++;
		}
	}
	if(id == B_ID)
	{
		while(i < a->b_len)
		{
			if(a->b_stack[i] == nb)
				index = i;
			i++;
		}
	}
	return(index);
}

int find_id(t_stacks* a, int nb)
{
	int i;

	i = 0;
	while(i < a->a_len)
	{
		if(a->a_stack[i++] == nb)
			return(A_ID);
	}
	i = 0;
	while(i < a->b_len)
	{
		if(a->b_stack[i++] == nb)
			return(B_ID);
	}
	return(FALSE);
}


int find_biggest(t_stacks* a)
{
	int i;
	int big;
	
	i = 0;
	if(a->a_len >= 1)
		big = a->a_stack[0];
	else if(a->b_len >= 1)
		big = a->b_stack[0];
	while(i < a->a_len)
	{
		if(a->a_stack[i] > big)
			big = a->a_stack[i];
		i++;
	}
	i = 0;
	while(i < a->b_len)
	{
		if(a->b_stack[i] > big)
			big = a->b_stack[i];
		i++;
	}
	return(big);
}

int	find_smallest(t_stacks* a)
{
	int i;
	int small;
	
	i = 0;
	if(a->a_len >= 1)
		small = a->a_stack[0];
	else if(a->b_len >= 1)
		small = a->b_stack[0];
	while(i < a->a_len)
	{
		if(a->a_stack[i] < small)
			small = a->a_stack[i];
		i++;
	}
	i = 0;
	while(i < a->b_len)
	{
		if(a->b_stack[i] < small)
			small = a->b_stack[i];
		i++;
	}
	return(small);
}
