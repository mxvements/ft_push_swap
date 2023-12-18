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
	//by movements
	int			sw = 0;
	int			ro = 0;
	int			rro = 0;

	ndcontent = node->content;
	i = ndcontent->indx;
	if (i == 0)
		cost = 0;
	else if (i <= (slen / 2))
		ro = i; //we only use swap to sort at the start, this is bette to maintain stack_b sorted
	else
		rro = slen - i;
	cost = ro + sw + rro;
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
		cost_tot = cost_max; //cost = the higher + push
	else
		cost_tot = content->cost + content->cost_out; //+push
	return (cost_tot);
}

t_dll	*getnextstacknode(t_dll **stack_b, int nbr)
{
	t_dll		*tmp;
	t_content	*tmpcont;

	tmp = *stack_b;
	tmpcont = tmp->content;
	//case1
	//nbr lower than the top, we find the first the lower to it to insert on top
	while (tmp->next && ((t_content *)tmp->content)->nbr < nbr)
	{
		tmp = tmp->next;
		tmpcont = tmp->content;
		if (((t_content *)tmp->content)->nbr > nbr)
			return (tmp);
	}
	//case2 and 3
	//nbr higher than the top, we start from the bottom
	//nbr lower than the last, we find the first higher to it to insert it after (return the next)
	tmp = ft_dlllast(*stack_b);
	tmpcont = tmp->content;
	if (nbr > ((t_content *)tmp->content)->nbr)
		return (*stack_b);
	while (tmp->prev && ((t_content *)tmp->content)->nbr > nbr) //BROKEN HERE
	{
		tmp = tmp->prev;
		tmpcont = tmp->content;
		if (((t_content *)tmp->content)->nbr < nbr)
			return (tmp->next); //we need to return the first that is lower
	}
	//case left: the number is a new max.
	tmp = *stack_b;
	tmpcont = tmp->content;
	while (tmp->next)
	{
		tmpcont = tmp->content;
		if (tmpcont->nbr > ((t_content *)tmp->next->content)->nbr)
			return (tmp->next);
		tmp = tmp->next;
	}
	return (*stack_b);
}

//https://medium.com/@ayogun/push-swap-c1f5d2d41e97
void	getcost_a(t_dll **stack_a, t_dll **stack_b)
{
	t_dll		*tmp;
	t_dll		*node;
	t_content	*ndcontent;
	const int	slen_a = s_size(stack_a);
	const int	slen_b = s_size(stack_b);

	node = (*stack_a);
	while (node)
	{
		//update node info
		ndcontent = node->content;
		ndcontent->slen = slen_a;
		ndcontent->cost = getnodecost(node, slen_a);
		//get the node in the next stack -> this should be a funct
		tmp = getnextstacknode(stack_b, ndcontent->nbr);
		//update 'out'node info //must update its own info as well
		ndcontent->slen_out = slen_b;
		ndcontent->indx_out = ((t_content *)tmp->content)->indx;
		ndcontent->cost_out = getnodecost(tmp, slen_b);
		ndcontent->cost_tot = gettotalcost(node);
		node = node->next;
	}
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
		//update node info
		ndcontent = node->content;
		ndcontent->slen = slen_b;
		ndcontent->cost = getnodecost(node, slen_b);
		//get the node in the next stack -> this should be a funct
		tmp = getnextstacknode(stack_a, ndcontent->nbr);
		//update 'out'node info //must update its own info as well
		ndcontent->slen_out = slen_a;
		ndcontent->indx_out = ((t_content *)tmp->content)->indx;
		ndcontent->cost_out = getnodecost(tmp, slen_a);
		ndcontent->cost_tot = gettotalcost(node);
		node = node->next;
	}
}