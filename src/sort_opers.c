/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:59:35 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/29 16:37:33 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/push_swap.h"

// static void	count_way(t_stacks *a, int pos_a, int pos_b, int size, int way)
// {
// 	const int	nb_a;
// 	const int	nb_b;
// 	int			i;
// 	int			pos1;
// 	int			pos2;

// 	nb_a = get_nb(a, pos_a, A_ID);
// 	nb_b = get_nb(a, pos_b, B_ID);
// 	if (a->b_len <= 1 || a->a_len <= 1)
// 		return ;
// 	i = 0;
// 	pos1 = -1;
// 	pos2 = -1;
// 	while (1)
// 	{
// 		if (way == BOTH_UP)
// 			rr(a);
// 		if (way == BOTH_DW)
// 			rrr(a);
// 		pos1 = get_index(a, nb_a, A_ID);
// 		pos2 = get_index(a, nb_b, B_ID);
// 		if ((pos1 == 0 || pos2 == 0) && size == BIGGER)
// 			break ;
// 		if ((pos1 == 0 || pos2 == a->b_len - 1) && size == SMALLER)
// 			break ;
// 	}
// }

// static void	
//solve_remain(t_stacks *a, int pos_a, int pos_b, int size, int way)
// {
// 	if (pos_a == 0)
// 	{
// 		if (size == BIGGER)
// 			makeitgotop(a, pos_b, way, B_ID);
// 		if (size == SMALLER)
// 			makeitgobot(a, pos_b, way, B_ID);
// 	}
// 	else
// 		makeitgotop(a, pos_a, way, A_ID);
// }

// static void	makeitgo(t_stacks *a, int pos_a, int pos_b, int size, int way)
// {
// 	if (way == ONLY_AUP)
// 		makeitgotop(a, pos_a, GO_UP, A_ID);
// 	else
// 		makeitgotop(a, pos_a, GO_DW, A_ID);
// 	if (size == BIGGER)
// 	{
// 		if (way == ONLY_AUP)
// 			makeitgotop(a, pos_b, GO_DW, B_ID);
// 		else
// 			makeitgotop(a, pos_b, GO_UP, B_ID);
// 	}
// 	else
// 	{
// 		if (way == ONLY_AUP)
// 			makeitgobot(a, pos_b, GO_DW, B_ID);
// 		else
// 			makeitgobot(a, pos_b, GO_UP, B_ID);
// 	}
// }

// void	set_pos(t_stacks *x, int pos_a, int pos_b, int size)
// {
// 	const int	way;
// 	const int	nb_a;
// 	const int	nb_b;

// 	way = compare_way(x, pos_a, pos_b, size);
// 	nb_a = get_nb(x, pos_a, A_ID);
// 	nb_b = get_nb(x, pos_b, B_ID);
// 	if (way == BOTH_UP || way == BOTH_DW)
// 	{
// 		count_way(x, pos_a, pos_b, size, way);
// 		pos_a = get_index(x, nb_a, A_ID);
// 		pos_b = get_index(x, nb_b, B_ID);
// 		solve_remain(x, pos_a, pos_b, size, way);
// 	}
// 	else
// 		makeitgo(x, pos_a, pos_b, size, way);
// 	print_allarray(x);
// }

// int	compare_distance(t_stacks *a, int nbx, int small, int big)
// {
// 	int	dis1;
// 	int	dis2;

// 	dis1 = best_distance(a, small, nbx, SMALLER);
// 	dis2 = best_distance(a, big, nbx, BIGGER);
// 	if (dis1 == dis2)
// 		return (EQUAL);
// 	if (dis1 < dis2)
// 		return (SMALLER);
// 	else
// 		return (BIGGER);
// }
