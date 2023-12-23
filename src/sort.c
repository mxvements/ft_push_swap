/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:22:22 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/23 17:20:04 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_b_save3(t_dll **stack_a, t_dll **stack_b)
{
	while (s_size(stack_a) > 3)
		push_b(stack_a, stack_b);
}

void	sort3_asc(t_dll **stack)
{
	const t_content	*a = (*stack)->content;
	const t_content	*b = (*stack)->next->content;
	const t_content	*z = ft_dlllast(*stack)->content;

	if (a->nbr > z->nbr && a->nbr > b->nbr && b->nbr == z->nbr)
		swap(stack, 'a');
	else if (a->nbr > z->nbr && a->nbr > b->nbr && b->nbr > z->nbr)
	{
		swap(stack, 'a');
		rvrot(stack, 'a');
	}
	else if (a->nbr > z->nbr && a->nbr > b->nbr && b->nbr < z->nbr)
		rot(stack, 'a');
	else if (a->nbr > z->nbr && a->nbr < b->nbr && b->nbr > z->nbr)
		rvrot(stack, 'a');
	else if (a->nbr < z->nbr && a->nbr > b->nbr && b->nbr < z->nbr)
		swap(stack, 'a');
	else if (a->nbr < z->nbr && a->nbr < b->nbr && b->nbr > z->nbr)
	{
		rvrot(stack, 'a');
		swap(stack, 'a');
	}
}

void	sort3_desc(t_dll **stack)
{
	const t_content	*a = (*stack)->content;
	const t_content	*b = (*stack)->next->content;
	const t_content	*z = ft_dlllast(*stack)->content;

	if (a->nbr < z->nbr && a->nbr < b->nbr && b->nbr == z->nbr)
		swap(stack, 'b');
	else if (a->nbr < z->nbr && a->nbr < b->nbr && b->nbr < z->nbr)
	{
		swap(stack, 'b');
		rvrot(stack, 'b');
	}
	else if (a->nbr < z->nbr && a->nbr < b->nbr && b->nbr > z->nbr)
		rot(stack, 'b');
	else if (a->nbr < z->nbr && a->nbr > b->nbr && b->nbr < z->nbr)
		rvrot(stack, 'b');
	else if (a->nbr > z->nbr && a->nbr < b->nbr && b->nbr > z->nbr)
		swap(stack, 'b');
	else if (a->nbr > z->nbr && a->nbr > b->nbr && b->nbr < z->nbr)
	{
		rvrot(stack, 'b');
		swap(stack, 'b');
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
	if (s_size(stack_a) == 1)
		return ;
	else if (s_size(stack_a) <= 3)
		sort3_c(stack_a, 'a');
	else
	{
		push_b_save3(stack_a, stack_b);
		sort3_c(stack_a, 'a');
		while (s_size(stack_b) >= 1)
		{
			getcost(stack_a, stack_b);
			movecheapest(stack_a, stack_b);
		}
		lastrotate(stack_a);
	}
}
