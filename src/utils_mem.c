/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:04:25 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/09 15:04:50 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void all_free(t_stacks *a)
{
		if(a->a_stack)
			free(a->a_stack);
		if(a->b_stack)
			free(a->b_stack);
		if(a)
			free(a);
}

void check_malloc(t_stacks* a, int stack_alloc)
{

	if (stack_alloc == TRUE)
	{
		if (a->a_stack == NULL || a->b_stack == NULL)
			err_exit(a, "memory allocation for stacks failed.");
	}
	if (stack_alloc == FALSE)
	{
		if(a == NULL)
			err_exit(a, "memory allocation failed.");
	}
}

void check_malloc_strints(int* nbs, char* tmp, int type)
{
	if (type == 1)
	{
		if(tmp)
			free(tmp);
	}
	if(nbs)
		free(nbs);
}
