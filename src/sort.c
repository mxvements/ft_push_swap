/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:22:22 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/19 23:53:51 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_b_save3(t_dll **stack_a, t_dll **stack_b)
{
	while (s_size(stack_a) > 3)
		push_b(stack_a, stack_b); //check this
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
	nxtcontent = tmp->next->content;
	if (tmpcontent->nbr > lstcontent->nbr && tmpcontent->nbr > nxtcontent->nbr)
		rot(stack, 'a');
	if (tmpcontent->nbr > lstcontent->nbr && tmpcontent->nbr < nxtcontent->nbr)
		rvrot(stack, 'a');
	tmp = *stack;
	while (tmp->next)
	{
		tmpcontent = tmp->content;
		if (tmpcontent->nbr > ((t_content *)tmp->next->content)->nbr)
		{
			swap(&tmp, 'a');
			tmp = *stack;
		}
		else
			tmp = tmp->next;
	}
}

void	sort3_desc(t_dll **stack)
{
	t_dll		*tmp;
	t_content	*tmpcontent;
	t_content	*nxtcontent;
	t_content	*lstcontent;

	tmp = *stack;
	tmpcontent = tmp->content;
	lstcontent = ft_dlllast(*stack)->content;
	nxtcontent = tmp->next->content;
	if (tmpcontent->nbr < lstcontent->nbr && tmpcontent->nbr < nxtcontent->nbr)
		rot(stack, 'b');
	if (tmpcontent->nbr < lstcontent->nbr && tmpcontent->nbr > nxtcontent->nbr)
		rvrot(stack, 'b');
	tmp = *stack;
	while (tmp->next)
	{
		tmpcontent = tmp->content;
		if (tmpcontent->nbr < ((t_content *)tmp->next->content)->nbr)
		{
			swap(&tmp, 'b');
			tmp = *stack;
		}
		else
			tmp = tmp->next;
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

void	sort(t_dll **stack_a, t_dll **stack_b)
{
	if (s_size(stack_a) < 4)
		sort3_c(stack_a, 'a');
	else
	{
		push_b_save3(stack_a, stack_b);
		sort3_c(stack_a, 'a');
		if (s_size(stack_b) <= 3)
			sort3_c(stack_b, 'b');
		else
		{
			while (s_size(stack_b) >= 1)
			{
				getcost(stack_a, stack_b);
				movecheapest(stack_a, stack_b);
			}
		}
		lastrotate(stack_a);
	}
}

