/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 22:27:47 by lightyagami       #+#    #+#             */
/*   Updated: 2023/08/09 18:08:09 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len <= start)
		size = 0;
	else if (s_len - start > len)
		size = len;
	else
		size = s_len - start;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (i < size)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
