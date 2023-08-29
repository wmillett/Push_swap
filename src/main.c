/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:42:25 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/29 16:05:51 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_method(t_stacks *a)
{
	a->a_len = a->size;
	a->b_len = 0;
	print_allarray(a);
	if (a->size <= 3)
		sort_for3(a, A_ID);
	else if (a->size <= 5)
		sort_for5(a);
	else
		sort_radix(a);
	print_allarray(a);
	return ;
}

int	main(int argc, char **argv)
{
	t_stacks	*c;
	int			size_n;

	c = NULL;
	if (check_arg(argc, argv) == 2)
		size_n = ft_count_a(argv[1], ' ');
	else
		size_n = argc - 1;
	check_size_n(size_n);
	c = malloc(sizeof(t_stacks));
	check_malloc(c, FALSE);
	c->a_stack = malloc(sizeof(int) * size_n + 1);
	c->b_stack = malloc(sizeof(int) * size_n + 1);
	check_malloc(c, TRUE);
	if (argc == 2)
		size_n = convert_str(c, argv[1]);
	else
		size_n = convert_argv(c, argc, argv);
	error_size_n(c, size_n);
	c->size = size_n;
	check_identical(c, size_n);
	sort_method(c);
	all_free(c);
}
