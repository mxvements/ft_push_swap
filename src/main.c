/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:37:37 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/08 00:03:14 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(void)
{
	t_dll	**stack_a;
	t_dll	**stack_b;

	/*if (argc != 2)
		return (0);*/
	char *s = "1 2 +3 7 5 6";

	stack_a = s_inithead();
	stack_b = s_inithead();
	//parse
	stack_a = a_evaluate(s, stack_a);
	//sort
	//sort(stack_a, stack_b);
	swap(stack_a, 'a');
	
	system("leaks -q push_swap");
	//check stack_a
	printf("size: %d\n", s_size(stack_a));
	s_print(stack_a);
	if (!stack_a || !(*stack_a))
		printf("stack vacio\n");
	if (s_issorted(stack_a) == 0)
	{
		printf("stack ordenado\n");
		s_free(stack_a);
	}
	return (0);
}
