/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_opers_both.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:25:18 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/24 15:48:13 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//Does both ra and rb at the same time.
//Pints "rr".
int rr(t_stacks* x)
{
	ra(x, TRUE);
	rb(x, TRUE);
	printf("rr\n");
	return(TRUE);
}

//Does both rra and rrb at the same time.
//Pints "rrr".
int rrr(t_stacks* x)
{
	rra(x, TRUE);
	rrb(x, TRUE);
	return(TRUE);
}

//Does both sa and sb at the same time.
//Pints "ss".
int ss(t_stacks* x)
{
	sa(x, TRUE);
	sb(x, TRUE);
	return(TRUE);
}
