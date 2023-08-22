/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:42:25 by wmillett          #+#    #+#             */
/*   Updated: 2023/08/09 18:48:37 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int find_max(int array[], int n) 
{
  int max; 
  int i;

  max = array[0];
  i = 1;
  while (i < n)
  {
    if (array[i] > max)
      max = array[i];
    i++;
  }
  return max;
}

void count_sort(int array[], int size, int pos) 
{
  int output[size + size];
  int max; 
  int i;

//   int test = 4;
  int j;
  printf("size: %i\n", size);
//   for(j = 0; j < 4; j++);
// 	printf("%i\n", array[j]);
j = 0;
while (j < size)
{
	printf("%i\n", array[j]);
	j++;

}
// exit(0);
	
  max = (array[0] / pos) % 10;
  printf("cs1\n");
  i = 1;
  while(i < size)
  {
	  printf("cs3: %i\n", i);
    if (((array[i] / pos) % 10) > max)
      max = array[i];
    i++;
  }
  printf("made\n");
  int count[max + 1];
	printf("made again\n");
	i = 0;
	while(i < max)
		count[i++] = 0;
	printf("nono\n");
	i = 0;
	while (i < size)
	 count[(array[i++] / pos) % 10]++;
    i = 1;
	while (i < 10)
	{
		 count[i] += count[i - 1];
		i++;
	}
	i = size - 1;
	while (i > 0)
	{
	printf("wut: %i\n", i);
    	output[count[(array[i] / pos) % 10] - 1] = array[i];
   		count[(array[i--] / pos) % 10]--;
  	}
	i = 0;
	while(i < size)
	{
		array[i] = output[i];
		i++;
	}
}

void radixsorting(int array[], int size) 
{
  int max;
  int pos;

  printf("here1\n");
  max = find_max(array, size);
  printf("here2\n");
  pos = 1;
  while (max / pos > 0)
  {
	printf("here3: %i\n", pos);
    count_sort(array, size, pos);
    pos *= 10;
  }
}

int main(int argc, char** argv)
{
  t_stacks *c;
  int size_n;

  c = NULL;
  if(check_arg(argc, argv) == 2)
    size_n = ft_count_a(argv[1], ' ');
  else
    size_n = argc - 1;
  check_size_n(size_n);
  c = malloc(sizeof(t_stacks));
  check_malloc(c, FALSE);
  c->a_stack = malloc(sizeof(int) * size_n + 1);
  c->b_stack = malloc(sizeof(int) * size_n + 1);
  check_malloc(c, TRUE);
	if (argc == 2)
    size_n = convert_str(c, argv[1]);
  else
	  size_n = convert_argv(c, argc, argv);
  error_size_n(c, size_n);
  c->size = size_n;
	check_identical(c, size_n);
	sort_method(c);
  all_free(c);
}
