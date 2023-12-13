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

void	sort3_asc(t_dll **stack)
{
	t_dll		*tmp;
	t_content	*tmpcontent;
	t_content	*nxtcontent;
	t_content	*lstcontent;

	tmp = *stack;
	tmpcontent = tmp->content;
	lstcontent = ft_dlllast(*stack)->content;
	if (tmpcontent->nbr > lstcontent->nbr)
		rot(stack, 'a');
	while (tmp->next)
	{
		tmpcontent = tmp->content;
		nxtcontent = tmp->next->content;
		if (tmpcontent->nbr > nxtcontent->nbr)
			swap(&tmp, 'a');
		else
		{
			tmp = tmp->next;
			continue ;
		}
		tmp = *stack;
	}
}

void	sort3_desc(t_dll **stack)
{
	t_dll		*tmp;
	t_content	*tmpcontent;
	t_content	*nxtcontent;
	t_content	*lstcontent;

	tmp = *stack;
	lstcontent = ft_dlllast(*stack)->content;
	tmpcontent = tmp->content;
	if (tmpcontent->nbr < lstcontent->nbr)
		rot(stack, 'a');
	while (tmp->next)
	{
		tmpcontent = tmp->content;
		nxtcontent = tmp->next->content;
		if (tmpcontent->nbr < nxtcontent->nbr)
			swap(&tmp, 'a');
		else
		{
			tmp = tmp->next;
			continue ;
		}
		tmp = *stack;
	}
}

void	sort3_c(t_dll **stack, char c)
{
	if (c == 'a')
		sort3_asc(stack);
	else if (c == 'b')
		sort3_desc(stack);
	else
		ft_putstr_fd("ERROR: wrong stack\n", 1);
}

/*
* 
*/
void	sort(t_dll **stack_a, t_dll **stack_b)
{
	s_updateindx(stack_a);
	s_updateindx(stack_b);
	if (s_size(stack_a) < 4)
		sort3_c(stack_a, 'a');
	if (s_size(stack_a) < 6)
	{
		push_b_save3(stack_a, stack_b);
		sort3_c(stack_a, 'a');
		sort3_c(stack_b, 'b');
		/*while (*stack_b)
		{
			push_a(stack_a, stack_b);
			sort3_c(stack_a, 'a');
		}*/
	}
	if (s_size(stack_a) <= 6)
	{
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		sort3_c(stack_b, 'b');

		s_updateindx(stack_a);
		s_updateindx(stack_b);
		
		getcost_a(stack_a, stack_b);
	}
	s_updateindx(stack_a);
	s_updateindx(stack_b);
}

