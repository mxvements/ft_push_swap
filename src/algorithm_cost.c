/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:04:46 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/17 20:48:51 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int	getnodecost(t_dll *node, int slen)
{
	t_content	*ndcontent;
	int			i;
	int			cost;
	int			ro = 0;
	int			rro = 0;

	ndcontent = node->content;
	i = ndcontent->indx;
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

t_dll	*getnextstacknode(t_dll **stack_b, int nbr)
{
	t_dll		*tmp;
	t_content	*tmpcont;
	t_dll		*min;
	t_content	*mincont;
	t_dll		*max;
	t_content	*maxcont;

	//get min and max from the stack
	tmp = *stack_b;
	min =  tmp;
	max = tmp;
	while (tmp)
	{
		tmpcont = tmp->content;
		if (((t_content *)min->content)->nbr > tmpcont->nbr)
		{
			min = tmp;
			mincont = min->content;
		}
		if (((t_content *)max->content)->nbr < tmpcont->nbr)
		{
			max = tmp;
			maxcont = max->content;
		}	
		tmp = tmp->next;
	}
	//if the number is lower than the max && higher than the min
	if (nbr < ((t_content *)max->content)->nbr && nbr > ((t_content *)min->content)->nbr)
	{
		tmp = *stack_b;
		tmpcont = tmp->content;
		while (tmp->next && ((t_content *)tmp->content)->nbr < nbr)
		{
			tmp = tmp->next;
			tmpcont = tmp->content;
			if (((t_content *)tmp->content)->nbr > nbr)
				return (tmp);
		}
		tmp = ft_dlllast(*stack_b);
		tmpcont = tmp->content;
		while (tmp->prev && ((t_content *)tmp->content)->nbr > nbr)
		{
			tmp = tmp->prev;
			tmpcont = tmp->content;
			if (((t_content *)tmp->content)->nbr < nbr)
				return (tmp->next); 
		}
	}
	//if its a new max or a new min..
	else if (nbr > ((t_content *)max->content)->nbr)
	{
		if (max->next)
			return (max->next);
		else
			return (*stack_b);
	}
	else if (nbr < ((t_content *)min->content)->nbr)
		return (min);
	return (*stack_b);
}

void	getcost_b(t_dll **stack_a, t_dll **stack_b)
{
	t_dll		*tmp;
	t_dll		*node;
	t_content	*ndcontent;
	const int	slen_a = s_size(stack_a);
	const int	slen_b = s_size(stack_b);

	node = (*stack_b);
	while (node)
	{
		ndcontent = node->content;
		ndcontent->slen = slen_b;
		ndcontent->cost = getnodecost(node, slen_b);
		tmp = getnextstacknode(stack_a, ndcontent->nbr);
		ndcontent->slen_out = slen_a;
		ndcontent->indx_out = ((t_content *)tmp->content)->indx;
		ndcontent->cost_out = getnodecost(tmp, slen_a);
		ndcontent->cost_tot = gettotalcost(node);
		node = node->next;
	}
}
