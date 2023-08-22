/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:06:43 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/09 18:05:27 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t i;

	i = 0;
	p = malloc(count * size);
	if (!p)
		return (NULL);
	while (i < (count * size))
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}
