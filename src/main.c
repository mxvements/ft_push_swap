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

void	push_swap(char *s)
{
	t_dll	**stack_a;
	t_dll	**stack_b;

	if (*s == '\0')
		return ;
	stack_a = s_inithead();
	stack_b = s_inithead();
	if (!stack_a || !stack_b)
	{
		s_free(stack_a);
		s_free(stack_b);
		return ;
	}
	if (stack_a && stack_b)
	{
		stack_a = a_parse(s, stack_a);
		sort(stack_a, stack_b);
	}
	if (s_issorted(stack_a) == 0)
		printf("stack ordenado\n");
	s_print(stack_a);
	s_free(stack_a);
	s_free(stack_b);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	else
		push_swap(argv[1]);
	system("leaks -q push_swap");
	return (0);
}
