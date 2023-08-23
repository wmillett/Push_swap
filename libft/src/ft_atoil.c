/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:06:12 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/23 17:13:20 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

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
	while (str[n] == '-' || str[n] == '+')
	{
		if (str[n] == '-')
			i++;
		n++;
	}
	while ((str[n] >= '0' && str[n] <= '9'))
		result = result * 10 + str[n++] - '0';
	if (i >= 2)
		return (ATOL_ER2);
	if (i % 2 == 1)
		result = -result;
	if (result > INT_MAX || result < INT_MIN)
		return (ATOL_ER);
	return (result);
}
