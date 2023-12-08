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
	char *s = "4 67 -3 87 23"; //5 nbrs
	t_dll	**stack_a;
	
	stack_a = (t_dll **)malloc(sizeof(t_dll *));
	if (!stack_a)
		return (0);
	stack_a = a_evaluate(s, stack_a);
	printf("size: %d\n", s_size(stack_a));
	s_print(stack_a);
	system("leaks -q push_swap");

	return (0);
}
