/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lightyagami <lightyagami@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:15:59 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/14 00:18:40 by lightyagami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void print_array(t_stacks *a, int id) 
{
  int i;

  i = 0;
  if(id == A_ID)
  {
	printf("STACK 'A': ");
  	while(i < a->a_len)
  	{
  	  printf("%d  ", a->a_stack[i]);
  	  i++;
  	}
  }
  if(id == B_ID)
  {
	printf("STACK 'B': ");
  	while(i < a->b_len)
  	{
  	  printf("%d  ", a->b_stack[i]);
  	  i++;
  	}
  }
  printf("\n");
}

void	print_allarray(t_stacks *a)
{
	print_array(a, A_ID);
	print_array(a, B_ID);
	// int i;

	// i = 0;
	// if(id == A_ID)
	// {
	// 	printf("STACK 'A': ");
	// 	while(a->a_stack[i])
	// 	{
	// 		printf("%d ", a->a_stack[i]);
	// 		i++;
	// 	}
	// }
	// if(id == B_ID)
	// {
	// 	printf("STACK 'B': ");
	// 	while(a->b_stack[i])
	// 	{
	// 		printf("%d ", a->b_stack[i]);
	// 		i++;
	// 	}
	// }
	// printf("\n");
}
