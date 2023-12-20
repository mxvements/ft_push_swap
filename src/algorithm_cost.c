/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:46 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/19 23:37:31 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_dll	*findnextnode_inbounds(int nbr, t_dll **stack)
{
	t_dll		*tmp;
	t_content	*tmpcont;

	tmp = *stack;
	tmpcont = tmp->content;
	while (tmp->next && tmpcont->nbr < nbr)
	{
		tmp = tmp->next;
		tmpcont = tmp->content;
		if (tmpcont->nbr > nbr)
			return (tmp);
	}
	tmp = ft_dlllast(*stack);
	tmpcont = tmp->content;
	while (tmp->prev && tmpcont->nbr > nbr)
	{
		tmp = tmp->prev;
		tmpcont = tmp->content;
		if (tmpcont->nbr < nbr)
			return (tmp->next);
	}
	return (*stack);
}

t_dll	*findnextnode(int nbr, t_dll **stack)
{
	t_dll		*tmp;
	t_dll		*min;
	t_dll		*max;

	tmp = *stack;
	min = tmp;
	max = tmp;
	s_findbounds(stack, &min, &max);
	if (nbr > ((t_content *)max->content)->nbr
		|| nbr < ((t_content *)min->content)->nbr)
	{
		if (nbr > ((t_content *)max->content)->nbr)
		{
			if (max->next)
				return (max->next);
			else
				return (*stack);
		}
		else if (nbr < ((t_content *)min->content)->nbr)
			return (min);
	}
	return (findnextnode_inbounds(nbr, stack));
}

int	getnodecost(t_dll *node, int slen)
{
	t_content	*ndcontent;
	int			i;
	int			cost;
	int			ro;
	int			rro;

	ndcontent = node->content;
	i = ndcontent->indx;
	ro = 0;
	rro = 0;
	if (i == 0)
		cost = 0;
	else if (i <= (slen / 2))
		ro = i;
	else
		rro = slen - i;
	cost = ro + rro;
	return (cost);
}

int	gettotalcost(t_dll *node)
{
	t_content	*content;
	int			indx;
	int			indx_out;
	int			cost_max;
	int			cost_tot;

	content = node->content;
	indx = content->indx;
	indx_out = content->indx_out;
	if (content->cost >= content->cost_out)
		cost_max = content->cost;
	else
		cost_max = content->cost_out;
	if ((indx <= (content->slen / 2) && indx_out <= (content->slen_out / 2))
		|| (indx > (content->slen / 2) && indx_out > (content->slen_out / 2)))
		cost_tot = cost_max;
	else
		cost_tot = content->cost + content->cost_out;
	return (cost_tot);
}

void	getcost(t_dll **stack_out, t_dll **stack_self)
{
	t_dll		*tmp;
	t_dll		*node;
	t_content	*ndcontent;
	const int	slen_a = s_size(stack_out);
	const int	slen_b = s_size(stack_self);

	node = (*stack_self);
	s_updateindx(stack_out);
	s_updateindx(stack_self);
	while (node)
	{
		ndcontent = node->content;
		ndcontent->slen = slen_b;
		ndcontent->cost = getnodecost(node, slen_b);
		tmp = findnextnode(ndcontent->nbr, stack_out);
		ndcontent->slen_out = slen_a;
		ndcontent->indx_out = ((t_content *)tmp->content)->indx;
		ndcontent->cost_out = getnodecost(tmp, slen_a);
		ndcontent->cost_tot = gettotalcost(node);
		node = node->next;
	}
}
