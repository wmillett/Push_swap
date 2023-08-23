/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:21:13 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/23 16:42:57 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>

# define ATOL_ER -2147483650
# define ATOL_ER2 -2147483651
# define ERROR -1
# define TRUE 1
# define FALSE 0

//int
int		ft_isspace(char c);
int		ft_isoper(char c);
int		ft_strlen(char *s);
long	ft_atoil(const char *str);
int		ft_isdigit(int nb);
//str
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
#endif
