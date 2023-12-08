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

t_dll	**s_inithead(void)
{
	t_dll	**stack;

	stack = (t_dll **)malloc(sizeof(t_dll *));
	if (!stack)
		return (0);
	*stack = NULL;
	return (stack);
}
int	s_isnodedup(t_dll **head, t_dll *node)
{
	t_dll	*tmp;
	int		flag;

	flag = 0;
	tmp = *head;
	while (tmp)
	{
		if (*(int *)(tmp->content) == *(int *)(node->content))
			flag = 1;
		tmp = tmp->next;
	}
	return(flag);
}

int main(void)
{
	char *s = "4 6 2147483647 -3 7 23";

	t_dll	**stack_a;
	//t_dll	**stack_b;
	
	//stack_b = s_inithead();
	stack_a = s_inithead();

	stack_a = a_evaluate(s, stack_a);
	system("leaks -q push_swap");
	
	printf("size: %d\n", s_size(stack_a));
	s_print(stack_a);

	return (0);
}
