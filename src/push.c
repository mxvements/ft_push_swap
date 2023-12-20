/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:30:51 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/10 17:11:39 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_dll **stack_a, t_dll **stack_b)
{
	t_content	*tmp;
	t_dll		*node;

	tmp = (t_content *)s_pop(stack_b);
	node = ft_dllnew((void *)(tmp));
	s_push(stack_a, node);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_dll **stack_a, t_dll **stack_b)
{
	t_content	*tmp;
	t_dll		*node;

	tmp = (t_content *)s_pop(stack_a);
	node = ft_dllnew((void *)(tmp));
	s_push(stack_b, node);
	ft_putstr_fd("pb\n", 1);
}
