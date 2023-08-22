/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:43:53 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/21 18:40:12 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft/inc/libft.h"
# include <stdio.h>

# define SUCCESS 1
# define FAILURE 0
# define ERROR -1
# define ERROR2 -2
# define A_ID 1
# define B_ID 2
# define go_r 1
# define go_rr 2
# define BIGGER 1
# define SMALLER -1
# define EQUAL 0
# define INVALID -1

typedef struct s_stack
{
	int size;
	int len;
	int	*stack;
}		t_stack;

typedef struct s_stacks
{
	int size;
	int a_len;
	int b_len;
	int *a_stack;
	int *b_stack;
} 		t_stacks;

typedef struct s_index
{
	int pos_a;
	int pos_b;
}		t_index;
 
//error ----------------------------
void	printerror(char *str);
void 	err_exit(t_stacks *a, char *str);
void 	error_size_n(t_stacks* a, int type);
void 	leave(t_stacks* x);
//parse ----------------------------
int		check_arg(int argc, char **argv);
int 	convert_argv(t_stacks *a, int argc, char** argv);
int 	convert_1argv(t_stacks *a, char* str, int index);
void 	check_identical(t_stacks *a, int size);
void 	check_size_n(int size_n);
//sort_small -----------------------
void 	sort_for3(t_stacks *a, int id);
void 	sort_for5(t_stacks* a);
//find_smaller ---------------------
int 	find_nextsmall(t_stacks* a, int id, int index);
//find_bigger ----------------------
int 	find_next(t_stacks* a, int id, int index);
//sort -----------------------------
int 	pos_next(t_stacks* a, int index, int id, int size);
int 	get_next(t_stacks* a, int index, int id, int rt_value);
int 	least_moves(t_stacks* a, int id);
void	sortforbig(t_stacks* x);
void 	sort_method(t_stacks *a);
//sort_opers -------------------------
void 	set_pos(t_stacks* x, int pos_a, int pos_b, int size);
int 	compare_distance(t_stacks* a, int nbx, int small, int big);
//stack_opers_a ----------------------
int	 	sa(t_stacks *x);
int 	ra(t_stacks *x);
int 	rra(t_stacks *x);
int 	pa(t_stacks *x);
//stack_opers_b ----------------------
int	 	sb(t_stacks *x);
int 	rb(t_stacks *x);
int 	rrb(t_stacks *x);
int 	pb(t_stacks *x);
//utils ----------------------------
int 	get_nb(t_stacks* a, int index, int id);
int 	count_ints(char* str);
int 	is_sorted(t_stacks* a);
// int 	intsplit(t_stacks* a, char* tmp, int* res, char** argv, int len);
int 	issmallest(t_stacks* a, int id, int index);
int 	isbiggest(t_stacks* a, int id, int index);
//utils_dist ------------------------
void 	makebigtop(t_stacks* x, int id);
int 	way_bot(t_stacks* a, int index, int id);
void 	makeitgobot(t_stacks* a, int index, int dir, int id);
//utils_str ------------------------
int		ft_count_a(char *s, char c);
int 	convert_str(t_stacks* a, char* str);
//utils_pos -------------------------
int 	pos_biggest(t_stacks *a, int id);
int 	pos_smallest(t_stacks *a, int id);
int 	closest_totop(t_stacks* a, int pos1, int pos2, int id);
//utils_sort ------------------------
int 	way_top(t_stacks* a, int index, int id);
int 	swap_bigtop(t_stacks* a, int id);
void 	makeitgotop(t_stacks* a, int index, int dir, int id);
int 	distance_top(t_stacks* a, int index, int id, int dir);
int 	totaldistance(t_stacks* a, int pos_a, int pos_b, int size);
//utils_stack -----------------------
int 	find_index(t_stacks* a, int nb);
int 	get_index(t_stacks* a, int nb, int id);
int 	find_id(t_stacks* a, int nb);
int 	find_biggest(t_stacks* a);
int		find_smallest(t_stacks* a);
//utils_print -----------------------
void 	print_array(t_stacks *a, int id); 
void	print_allarray(t_stacks *a);
//utils_mem --------------------------
void 	all_free(t_stacks *a);
void 	check_malloc(t_stacks* a, int stack_alloc);
void 	check_malloc_strints(int* nbs, char* tmp, int type);
//handle_array -----------------------
void 	swaparray(t_stacks* x, int id);
#endif
