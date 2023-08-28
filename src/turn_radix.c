/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:06:49 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/27 22:57:46 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"



// static int get_len(t_stacks* a)
// {
// 	const int len = find

	
// }



static int get_small(t_stacks* a)
{
	int nb;
	int pos;

	nb = find_smallest(a);
	pos = get_index(a, nb, A_ID);
	return(pos);
}

static int findthebig(t_stacks* a)
{
	int i;
	int pos;
	
	pos = 0;
	i = 1;
	while(i < a->a_len)
	{
		if(a->a_stack[i] > a->a_stack[pos])
			pos = i;
		i++;
	}
	return(pos);
}


static int next(t_stacks* a, int index)
{
	int	i;
	int pos;

	
	pos = findthebig(a);
	i = 0;
	while (i < a->a_len)
	{
		if (a->a_stack[i] > a->a_stack[index]
			&& a->a_stack[i] < a->a_stack[pos])
			pos = i;
		i++;
	}
	return(pos);
}

void transform_to_radix(t_stacks* a)
{
	int i;
	int index[a->size];
	int tmp;

	i = 0;
	while(i < a->size)
	{
		if (i == 0)
			index[i] = get_small(a);
		else
		{
			tmp = next(a, index[i - 1]);
			index[i] = tmp;
		}
		i++;
	}
	i = 0;
	while(i < a->size)
	{
		a->a_stack[index[i]] = i;
		i++;
	}
	// tmp = a->size - 1;
	// return(tmp);
}
