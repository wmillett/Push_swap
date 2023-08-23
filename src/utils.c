/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:55:34 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/23 16:54:49 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_nb(t_stacks *a, int index, int id)
{
	int	nb;

	if (id == A_ID)
		nb = a->a_stack[index];
	if (id == B_ID)
		nb = a->b_stack[index];
	return (nb);
}

int	issmallest(t_stacks *a, int id, int index)
{
	int	i;

	i = 0;
	if (id == A_ID)
	{
		while (i < a->a_len)
		{
			if (i == index)
				i++;
			else if (a->a_stack[i++] < a->a_stack[index])
				return (FALSE);
		}
	}
	if (id == B_ID)
	{
		while (i < a->b_len)
		{
			if (i == index)
				i++;
			else if (a->b_stack[i++] < a->b_stack[index])
				return (FALSE);
		}
	}
	return (TRUE);
}

int	isbiggest(t_stacks *a, int id, int index)
{
	int	i;

	i = 0;
	if (id == A_ID)
	{
		while (i < a->a_len)
		{
			if (i == index)
				i++;
			else if (a->a_stack[i++] > a->a_stack[index])
				return (FALSE);
		}
	}
	if (id == B_ID)
	{
		while (i < a->b_len)
		{
			if (i == index)
				i++;
			else if (a->b_stack[i++] > a->b_stack[index])
				return (FALSE);
		}
	}
	return (TRUE);
}

int	is_sorted(t_stacks *a)
{
	int	i;
	int	tmp;

	if (a->a_len == a->size && a->size > 1)
	{
		i = 1;
		tmp = a->a_stack[0];
		while (i < a->a_len)
		{
			if (tmp > a->a_stack[i])
				return (FALSE);
			tmp = a->a_stack[i];
			i++;
		}
		return (TRUE);
	}
	return (FALSE);
}
