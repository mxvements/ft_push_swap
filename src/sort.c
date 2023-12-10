/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:22:22 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/11 00:35:47 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_b_save3(t_dll **stack_a, t_dll **stack_b)
{
	t_dll	*node;

	if (!stack_a || !stack_b)
		return ;
	node = *stack_a;
	while (node->next->next->next != NULL)
	{
		node = node->next;
		push_b(stack_a, stack_b);
	}
}

void	sort3(t_dll **stack, char c)
{
	t_dll		*tmp;
	t_content	*tmpcontent;
	t_content	*nxtcontent;
	t_content	*lstcontent;
	
	tmp = *stack;
	while (tmp->next)
	{
		tmpcontent = tmp->content;
		nxtcontent = tmp->next->content;
		lstcontent = ft_dlllast(*stack)->content;
		if ((c == 'a') && (tmpcontent->nbr > lstcontent->nbr))
			tmp = rot(stack, 'a');
		else if ((c == 'a') && (tmpcontent->nbr > nxtcontent->nbr))
			tmp = swap(&tmp, 'a');
		else if ((c == 'b') && (tmpcontent->nbr < lstcontent->nbr))
			tmp = rot(stack, 'b');
		else if ((c == 'b') && (tmpcontent->nbr < nxtcontent->nbr))
			tmp = swap(&tmp, 'b');
		else
			tmp = tmp->next;
	}	
}

void	sort(t_dll **stack_a, t_dll **stack_b)
{
	push_b_save3(stack_a, stack_b);
	sort3(stack_a, 'a');
	if (s_size(stack_b) == 3)
	{
		sort3(stack_b, 'b');
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
}

