/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:02:38 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/23 16:54:26 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	free_split(char **args, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	ft_count_a(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

int	convert_str(t_stacks *a, char *str)
{
	char	**args;
	int		nb;
	int		i;
	long	check;

	i = 0;
	nb = ft_count_a(str, ' ');
	args = ft_split(str, ' ');
	if (args == NULL)
		err_exit(a, "malloc failed.");
	while (i < nb)
	{
		check = ft_atoil(args[i]);
		if (check <= ATOL_ER)
		{
			free_split(args, nb);
			if (check == ATOL_ER)
				err_exit(a, "contains a number too large for int.");
			err_exit(a, "argument contains too many '-' symbols.");
		}
		a->a_stack[i] = (int)check;
		i++;
	}
	free_split(args, nb);
	return (nb);
}
