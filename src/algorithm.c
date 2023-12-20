/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:14:45 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/17 23:15:38 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	getcheapest(t_dll **stack)
{
	t_dll	*tmp;
	int		cheapest_idx;
	int		cheapest_cost;

	tmp = (*stack);
	cheapest_cost = ((t_content *)tmp->content)->cost_tot;
	cheapest_idx = ((t_content *)tmp->content)->indx;
	while (tmp)
	{
		if (((t_content *)tmp->content)->cost_tot < cheapest_cost)
		{
			cheapest_cost = ((t_content *)tmp->content)->cost_tot;
			cheapest_idx = ((t_content *)tmp->content)->indx;
		}
		tmp = tmp->next;
	}
	return (cheapest_idx);
}

void	movecheapest(t_dll **stack_out, t_dll **stack_self)
{
	int			cheapest;
	t_dll		*node;
	t_content	*ndcontent;

	cheapest = getcheapest(stack_self);
	node = (*stack_self);
	while (node)
	{
		ndcontent = node->content;
		if ((int)(ndcontent->indx) != cheapest)
			node = node->next;
		if ((int)(ndcontent->indx) == cheapest)
		{
			movenode(node, stack_out, stack_self);
			push_a(stack_out, stack_self);
			break;
		}
	}
}

void	lastrotate(t_dll **stack)
{
	t_dll		*min;
	t_dll		*max;
	t_content	*mincont;
	int			i;

	min = *stack;
	max = *stack;
	s_updateindx(stack);
	s_findbounds(stack, &min, &max);
	mincont = min->content;
	mincont->slen = s_size(stack);
	if ((int)mincont->indx <= (mincont->slen / 2))
	{
		i = mincont->indx;
		while (i-- > 0)
			rot(stack, 'a');
	}
	else if ((int)mincont->indx > (mincont->slen / 2))
	{
		i = mincont->slen - mincont->indx;
		while (i-- > 0)
			rvrot(stack, 'a');
	}
}
