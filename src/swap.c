/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:56:52 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/10 14:42:36 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_dll **stack, char c)
{
	t_content	*tmpnode;
	t_content	*tmpnext;

	//protections
	if (!stack || !(*stack))
		return ;
	//swap
	tmpnode = (*stack)->content;
	tmpnext = (*stack)->next->content;
	(*stack)->content = tmpnext;
	(*stack)->next->content = tmpnode;
	//update content, without touching nbr (for the future)
	//print
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	if (c == 'b')
		ft_putstr_fd("sb\n", 1);
	//check for other chars.. double swap?	
}

void	dswap(t_dll **stack_a, t_dll **stack_b)
{
	swap(stack_a, 'x');
	swap(stack_b, 'x');
	ft_putstr_fd("ss\n", 1);
}