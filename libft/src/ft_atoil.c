/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:06:12 by wmillett          #+#    #+#             */
/*   Updated: 2023/09/07 19:36:14 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	istheredigit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

long	ft_atoil(const char *str)
{
	int		i;
	int		n;
	long	result;

	result = 0;
	i = 0;
	n = 0;
	while (ft_isspace(str[n]))
		n++;
	if (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			i++;
		n++;
	}
	while ((str[n] >= '0' && str[n] <= '9'))
		result = result * 10 + str[n++] - '0';
	if (!istheredigit(str))
		return (ATOL_ER);
	if (result > INT_MAX || result < INT_MIN || i > 1)
		return (ATOL_ER);
	if (i % 2 == 1)
		return (-result);
	return (result);
}
