/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:55:34 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/21 15:36:10 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


int get_nb(t_stacks* a, int index, int id)
{	
	int nb;

	if(id == A_ID)
		nb = a->a_stack[index];
	if(id == B_ID)
		nb = a->b_stack[index];
	return(nb);
}

int issmallest(t_stacks* a, int id, int index)
{
	int i;

	i = 0;
	if(id == A_ID)
	{
		while(i < a->a_len)
		{
			if(i == index)
				i++;
			else if(a->a_stack[i++] < a->a_stack[index])
				return(FALSE);
		}
	}
	if(id == B_ID)
	{
		while(i < a->b_len)
		{
			if(i == index)
				i++;
			else if(a->b_stack[i++] < a->b_stack[index])
				return(FALSE);
		}
	}
	return(TRUE);
}

int isbiggest(t_stacks* a, int id, int index)
{
	int i;

	i = 0;
	if(id == A_ID)
	{
		while(i < a->a_len)
		{
			if(i == index)
				i++;
			else if(a->a_stack[i++] > a->a_stack[index])
				return(FALSE);
		}
	}
	if(id == B_ID)
	{
		while(i < a->b_len)
		{
			if(i == index)
				i++;
			else if(a->b_stack[i++] > a->b_stack[index])
				return(FALSE);
		}
	}
	return(TRUE);
}

int count_ints(char* str)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while(str[i])
	{
		while((ft_isoper(str[i]) || ft_isspace(str[i])) && str[i])
			i++;
		if(ft_isdigit(str[i]) && str[i])
			len++;
		while(ft_isdigit(str[i]) && str[i])
			i++;
	}
	return(len);
}

int is_sorted(t_stacks* a)
{
	int i;
	int tmp;
	
	if(a->a_len == a->size && a->size > 1)	
	{
		i = 1;
		tmp = a->a_stack[0];
		while(i < a->a_len)
		{
			if (tmp > a->a_stack[i])
				return(FALSE);
			tmp = a->a_stack[i];
			i++;
		}
		return(TRUE);
	}
	return(FALSE);
}






// int intsplit(t_stacks* a, char* tmp, int* res, char** argv, int len)
// {
// 	int i;
// 	int n_int;
// 	int j;
// 	int k;
	
// 	k = 0;
// 	i = 0;
// 	n_int = count_ints(argv[1]);
// 	if (n_int <= 0)
// 		return(n_int);
// 	check_malloc_strints(res, tmp, 0);
// 	while(argv[1][i])
// 	{
// 		printf("2\n");
// 		j = 0;
// 		tmp = malloc(sizeof(char) * len + 1);
// 		check_malloc_strints(res, tmp, 1);
// 		printf("3\n");
// 		while((ft_isoper(argv[1][i]) || ft_isspace(argv[1][i])) && argv[1][i])
// 			tmp[j++] = argv[1][i++];
// 		while(ft_isdigit(argv[1][i]) && argv[1][i])
// 			tmp[j++] = argv[1][i++];
// 		convert_1argv(a, tmp, k);
// 		printf("4\n");
// 		// free(tmp);
// 		printf("5\n");
// 		k++;
// 	}
// 	return(k + 1);
// }
