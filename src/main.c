/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:37:37 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/17 23:15:43 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_dll	**stack_a;
	t_dll	**stack_b;
	/*
	100nbr -> 700movs
	500nbr -> 5500mvs
	*/

	if (argc != 2)
		return (0);
	stack_a = s_inithead();
	stack_b = s_inithead();
	if (stack_a && stack_b)
	{
		stack_a = a_parse(argv[1], stack_a);
		sort(stack_a, stack_b);
	}
	else if (!stack_a || !(*stack_a))
	{
		printf("stack vacio\n");
		s_free(stack_a);
		s_free(stack_b);
	}
	if (s_issorted(stack_a) == 0)
	{
		printf("stack ordenado\n");
		s_free(stack_a);
	}
	system("leaks -q push_swap");
	return (0);
}
