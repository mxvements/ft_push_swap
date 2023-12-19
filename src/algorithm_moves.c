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

static void	movenode_drot(t_dll **node, t_dll **st_out, t_dll **st_self)
{
	t_content	*cont;
	int			moves_self;
	int			moves_out;

	cont = (*node)->content;
	moves_self = cont->cost;
	moves_out = cont->cost_out;
	while (moves_self > 0 && moves_out > 0)
	{
		drot(st_out, st_self);
		moves_self--;
		moves_out--;
	}
	while (moves_self == 0 && moves_out > 0)
	{
		rot(st_out, 'a');
		moves_out--;
	}
	while (moves_out == 0 && moves_self > 0)
	{
		rot(st_self, 'b');
		moves_self--;
	}
}

static void	movenode_drvrot(t_dll **node, t_dll **st_out, t_dll **st_self)
{
	t_content	*cont;
	int			moves_self;
	int			moves_out;

	cont = (*node)->content;
	moves_self = cont->cost;
	moves_out = cont->cost_out;
	while (moves_self > 0 && moves_out > 0)
	{
		drvrot(st_out, st_self);
		moves_self--;
		moves_out--;
	}
	while (moves_self == 0 && moves_out > 0)
	{
		rvrot(st_out, 'a');
		moves_out--;
	}
	while (moves_self > 0 && moves_out == 0)
	{
		rvrot(st_self, 'b');
		moves_self--;
	}
}

static void	movenode_rota_rvrotb(t_dll **node, t_dll **st_out, t_dll **st_self)
{
	t_content	*cont;
	int			moves_self;
	int			moves_out;

	cont = (*node)->content;
	moves_self = cont->cost;
	moves_out = cont->cost_out;
	while (moves_self > 0)
	{
		rot(st_self, 'b');
		moves_self--;
	}
	while (moves_out > 0)
	{
		rvrot(st_out, 'a');
		moves_out--;
	}
}

static void	movenode_rotb_rvrota(t_dll **node, t_dll **st_out, t_dll **st_self)
{
	t_content	*cont;
	int			moves_self;
	int			moves_out;

	cont = (*node)->content;
	moves_self = cont->cost;
	moves_out = cont->cost_out;
	while (moves_out > 0)
	{
		rot(st_out, 'a');
		moves_out--;
	}
	while (moves_self > 0)
	{
		rvrot(st_self, 'b');
		moves_self--;
	}
}

void	movenode(t_dll *node, t_dll **stack_out, t_dll **stack_self)
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
		movenode_drot(&node, stack_out, stack_self);
	else if (indx_self > (cont->slen / 2) && indx_out > (cont->slen_out / 2))
		movenode_drvrot(&node, stack_out, stack_self);
	else if (indx_self <= (cont->slen / 2) && indx_out > (cont->slen_out / 2))
		movenode_rota_rvrotb(&node, stack_out, stack_self);
	else if (indx_self > (cont->slen / 2) && indx_out <= (cont->slen_out / 2))
		movenode_rotb_rvrota(&node, stack_out, stack_self);
}