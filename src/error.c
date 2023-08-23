/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:34:57 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/23 16:45:18 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	printerror(char *str)
{
	printf("\033[0;31mError: %s\033[0m\n", str);
	exit(1);
}

void	err_exit(t_stacks *a, char *str)
{
	all_free(a);
	printerror(str);
}

void	error_size_n(t_stacks *a, int type)
{
	if (type == ERROR)
		err_exit(a, "argument does not fit in an integer.");
	if (type == ERROR2)
		err_exit(a, "argument contains characters invalid for an integer.");
}

void	leave(t_stacks *x)
{
	all_free(x);
	exit(0);
}
