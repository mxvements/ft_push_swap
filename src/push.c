/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:30:51 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/09 21:30:52 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_dll **stack_a, t_dll **stack_b)
{
	t_content	*tmp;
	t_dll		*node;

	//protections

	//
	tmp = (t_content *)s_pop(stack_b); //to check
	node = ft_dllnew((void *)(tmp));
	s_push(stack_a, node); //to check
	//print
	ft_putstr_fd("pa\n", 1);
	//check final state?
}