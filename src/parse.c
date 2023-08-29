/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:16:47 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/29 17:15:56 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc <= 1)
		exit(0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !ft_isspace(argv[i][j]) &&
				argv[i][j] != '-' && argv[i][j] != '+')
				printerror("contains an invalid character.");
			j++;
		}
		i++;
	}
	if (argc == 2)
		return (2);
	return (1);
}

void	check_size_n(int size_n)
{
	if (size_n == 0)
		exit(0);
}

int	convert_argv(t_stacks *a, int argc, char **argv)
{
	int		size;
	long	check;

	size = 1;
	while (size < argc)
	{
		check = ft_count_a(argv[size], ' ');
		if (check > 1)
			err_exit(a, "invalid argument format.");
		check = ft_atoil(argv[size]);
		if (check <= ATOL_ER)
		{
			if (check == ATOL_ER)
				err_exit(a,
					"contains an argument that is too large for an int.");
			err_exit(a, "argument contains too many '-' symbols.");
		}
		a->a_stack[size - 1] = (int)check;
		size++;
	}
	size--;
	return (size);
}

int	convert_1argv(t_stacks *a, char *str, int index)
{
	long	check;

	check = ft_atoil(str);
	if (check <= ATOL_ER)
	{
		free(str);
		if (check == ATOL_ER)
			err_exit(a, "contains an argument that is too large for an int.");
		err_exit(a, "argument contains too many '-' symbols.");
	}
	a->a_stack[index] = (int)check;
	return ((int)check);
}

void	check_identical(t_stacks *a, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (j == i && j + 1 >= size)
				break ;
			if (j == i)
				j++;
			else if (a->a_stack[j] == a->a_stack[i])
				err_exit(a, "contains same int twice.");
			else
				j++;
		}
		i++;
	}
}
