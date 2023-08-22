/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:30:59 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/09 18:02:12 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static size_t	ft_count_t(char const *s, char c)
{
	size_t	i;

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

static char	**ft_split2(char *s, char c, char **mem, size_t str)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (i < str)
	{
		while (*s && *s == c)
			s++;
		if (ft_strchr(s, c))
			len = ft_strchr(s, c) - s;
		else
			len = ft_strlen(s);
		mem[i] = ft_substr(s, 0, len);
		if (mem[i] == NULL)
		{
			mem = ft_free(mem);
			break ;
		}
		i++;
		s += len;
	}
	return (mem);
}

char	**ft_split(char *s, char c)
{
	size_t	str;
	char	**mem;

	if (!s)
		return (NULL);
	str = ft_count_t(s, c);
	mem = ft_calloc(sizeof(char *), (str + 1));
	if (!mem)
		return (NULL);
	return (ft_split2(s, c, mem, str));
}
