/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:35:22 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/24 15:55:46 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int pos_tobe_b(t_stacks* a, int index)
{
	int i;
	
	i = 0;
	while(i < a->b_len)
	{
		if(a->a_stack[index] > a->b_stack[i])
			break ;
		i++;
	}
	return(i);
}

int pos_tobe_a(t_stacks* a, int index)
{
	int i;
	
	i = 0;
	while(i < a->a_len)
	{
		if(a->b_stack[index] < a->a_stack[i])
			break ;
		i++;
	}
	return(i);
}

