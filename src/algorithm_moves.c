/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:46:24 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/19 17:46:25 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	movenode_drot(t_dll **node, t_dll **stack_a, t_dll **stack_b)
{
	t_content	*cont;
	int			moves_self;
	int			moves_out;

	cont = (*node)->content;
	moves_self = cont->cost;
	moves_out = cont->cost_out;
	while (moves_self > 0 && moves_out > 0)
	{
		drot(stack_a, stack_b);
		moves_self--;
		moves_out--;
	}
	while (moves_self == 0 && moves_out > 0)
	{
		rot(stack_a, 'a');
		moves_out--;
	}
	while (moves_out == 0 && moves_self > 0)
	{
		rot(stack_b, 'b');
		moves_self--;
	}
}

void	movenode_drvrot(t_dll **node, t_dll **stack_a, t_dll **stack_b)
{
	t_content	*cont;
	int			moves_self;
	int			moves_out;

	cont = (*node)->content;
	moves_self = cont->cost;
	moves_out = cont->cost_out;
	while (moves_self > 0 && moves_out > 0)
	{
		drvrot(stack_a, stack_b);
		moves_self--;
		moves_out--;
	}
	while (moves_self == 0 && moves_out > 0)
	{
		rvrot(stack_a, 'a');
		moves_out--;
	}
	while (moves_self > 0 && moves_out == 0)
	{
		rvrot(stack_b, 'b');
		moves_self--;
	}
}

void	movenode_rota_rvrotb(t_dll **node, t_dll **stack_a, t_dll **stack_b)
{
	t_content	*cont;
	int			moves_self;
	int			moves_out;

	cont = (*node)->content;
	moves_self = cont->cost;
	moves_out = cont->cost_out;
	while (moves_self > 0)
	{
		rot(stack_b, 'b');
		moves_self--;
	}
	while (moves_out > 0)
	{
		rvrot(stack_a, 'a');
		moves_out--;
	}
}

void	movenode_rotb_rvrota(t_dll **node, t_dll **stack_a, t_dll **stack_b)
{
	t_content	*cont;
	int			moves_self;
	int			moves_out;

	cont = (*node)->content;
	moves_self = cont->cost;
	moves_out = cont->cost_out;
	while (moves_out > 0)
	{
		rot(stack_a, 'a');
		moves_out--;
	}
	while (moves_self > 0)
	{
		rvrot(stack_b, 'b');
		moves_self--;
	}
}

void	movenode(t_dll *node, t_dll **stack_a, t_dll **stack_b)
{
	t_content	*cont;
	int			indx_self;
	int			indx_out;

	cont = node->content;
	indx_self = (int)cont->indx;
	indx_out = (int)cont->indx_out;
	if ((int)cont->cost == 0 && (int)cont->cost_out == 0)
		return ;
	else if (indx_self <= (cont->slen / 2) && indx_out <= (cont->slen_out / 2))
		movenode_drot(&node, stack_a, stack_b);
	else if (indx_self > (cont->slen / 2) && indx_out > (cont->slen_out / 2))
		movenode_drvrot(&node, stack_a, stack_b);
	else if (indx_self <= (cont->slen / 2) && indx_out > (cont->slen_out / 2))
		movenode_rota_rvrotb(&node, stack_a, stack_b);
	else if (indx_self > (cont->slen / 2) && indx_out <= (cont->slen_out / 2))
		movenode_rotb_rvrota(&node, stack_a, stack_b);
}