/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:22:08 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/17 17:47:50 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rot(t_dll **stack, char c)
{
	t_content	*tmp;
	t_dll		*tmpnode;

	tmp = (t_content *)s_pop(stack);
	tmpnode = ft_dllnew((void *)tmp);
	ft_dlladd_back(stack, tmpnode);
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
	else if (c == 'c')
		ft_putstr_fd("", 1);
	else
		ft_putstr_fd("ERROR: wrong stack\n", 1);
	return ;
}

void	drot(t_dll **stack_a, t_dll **stack_b)
{
	rot(stack_a, 'c');
	rot(stack_b, 'c');
	ft_putstr_fd("rr\n", 1);
}

void	rvrot(t_dll **stack, char c)
{
	t_dll		*last;
	t_dll		*newlast;
	t_content	*content;

	last = ft_dlllast(*stack);
	newlast = last->prev;
	content = (t_content *)last->content;
	free(last);
	newlast->next = NULL;
	s_push(stack, ft_dllnew((void *)content));
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
	else if (c == 'c')
		ft_putstr_fd("", 1);
	else
		ft_putstr_fd("ERROR: wrong stack\n", 1);
	return ;
}

void	drvrot(t_dll **stack_a, t_dll **stack_b)
{
	rvrot(stack_a, 'c');
	rvrot(stack_b, 'c');
	ft_putstr_fd("rrr\n", 1);
}
