/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:56:52 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/11 00:15:10 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_dll **stack, char c)
{
	t_content	*tmpnode;
	t_content	*tmpnext;

	if (!stack || !(*stack))
		return ;
	tmpnode = (*stack)->content;
	tmpnext = (*stack)->next->content;
	(*stack)->content = tmpnext;
	(*stack)->next->content = tmpnode;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
	else if (c == 'c')
		ft_putstr_fd("", 1);
	else
		ft_putstr_fd("ERROR: wrong stack\n", 1);
	return ;
}

void	dswap(t_dll **stack_a, t_dll **stack_b)
{
	swap(stack_a, 'c');
	swap(stack_b, 'c');
	ft_putstr_fd("ss\n", 1);
}