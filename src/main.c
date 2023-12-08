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

t_dll	**initstack(void)
{
	t_dll	**stack;

	stack = (t_dll **)malloc(sizeof(t_dll *));
	if (!stack)
		return (0);
	*stack = NULL;
	return (stack);
}

int main(void)
{
	char *s = "4 6 2147483647 -3 87 23";

	t_dll	**stack_a;
	//t_dll	**stack_b;
	
	//stack_b = initstack();
	stack_a = initstack();

	stack_a = a_evaluate(s, stack_a);
	system("leaks -q push_swap");
	
	printf("size: %d\n", s_size(stack_a));
	s_print(stack_a);

	return (0);
}
